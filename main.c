
#include "mcc_generated_files/system/system.h"
#include <string.h>
#include <ctype.h>

#define ID_addr 1
#define bat_type_addr 2
#define voltage_addr 3//3が下位ビット４が上位ビット
#define output_addr 5
#define voltage_offset_addr 6


unsigned char control_table[20] = {0xFF};
void init(void);
void putch(unsigned char Data);
char uart_mode;
void control_table_update(void);
void RS485master_mode(void);
void RS485slave_mode(void);
unsigned char buf[50]; 


int main(void)
{
    SYSTEM_Initialize();

    INTERRUPT_GlobalInterruptEnable(); 
    INTERRUPT_PeripheralInterruptEnable();
    Timer0_OverflowCallbackRegister(control_table_update);
    
    __delay_ms(2000);
    
    init();

    if(control_table[ID_addr] == 0){
        RS485master_mode();
        
    }else{
        RS485slave_mode();
    }

    
    
}

void putch(unsigned char Data)
{
    if(uart_mode == 0){
        while(!EUSART2_IsTxReady());
        EUSART2_Write(Data);
        while(!EUSART2_IsTxDone());
    }else if(uart_mode == 1){
        RS485_SW_SetHigh();
        EUSART1_Write(Data);
        if(Data == '\0'){
            RS485_SW_SetLow();
        }
    }
    
 
return;
}

void RS485master_mode(void){
    
    uart_mode = 0;
    
    while(1){
        
        //uart_mode = 0;
        //
    printf("Waiting command...\n");
        while(EUSART2_IsRxReady() == false);
        int buf_count = 0;
        do{
        while(EUSART2_IsRxReady() == false);
        buf[buf_count] = EUSART2_Read();
        
        buf_count++;
        
        if(buf_count >= 50){
            break;
        }
           
        }while(buf[buf_count - 1] != '-');
        
        buf[buf_count - 1] = '\0';
        //ここからコマンド処理を記載
//        printf("\n\n");
//        printf(buf);
//        printf("\ncount num:%d\n",buf_count);
//        printf("Waiting command...\n");
        
        if(strncmp(buf,"ON", strlen("ON")) == 0){
            if(isdigit(buf[3]) == 1){ 
                printf("Turn ON Board%d\n",buf[3] - '0');
                //実行用コマンド書く
                //数字から’０’を引くことで数値に変換できる
            }else{
                printf("Irregular Board num\n");
            }
            
        }
        
        if(strncmp(buf,"OFF", strlen("OFF")) == 0){
            if(isdigit(buf[4]) == 1){ 
                printf("Turn OFF Board%d\n",buf[4] - '0');
                //実行用コマンド書く
                //数字から’０’を引くことで数値に変換できる
            }else{
                printf("Irregular Board num\n");
            }
            
        }
        
        if(strncmp(buf,"GETV", strlen("GETV")) == 0){
            if(isdigit(buf[5]) == 1){ 
                printf("OK Board%d: ",buf[5] - '0');
                double voltage;
                
                voltage = (double)((control_table[voltage_addr+1]<<8)+control_table[voltage_addr])/1023 * 5.04 * 11;;
                
               //printf("%1lf",voltage);ここのなおしかたわからん
            }else{
                printf("Irregular Board num\n");
            }
            
        }
        
        
        
        
        //ここまでコマンド処理
        for(int i=0; i<50; i++){
            buf[i] = 0;
        }
        
        
        
        
    }
    
}
    
 
void RS485slave_mode(void){
        while(1);
    }
    


void init(void){
    RS485_SW_SetLow();
    LED_PD_SetHigh();
    
    SE_SetLow();
    
    control_table[ID_addr] = SW_bit1_PORT + SW_bit2_PORT * 2 + SW_bit3_PORT * 4;
    
    
    control_table[voltage_offset_addr] = FLASH_Read(6);
    if(control_table[voltage_offset_addr] == 0xFF){
        control_table[voltage_offset_addr] = 0;
    }
    
    uart_mode = 0;
    printf("System Initialized\n");
    __delay_ms(10);
}

void control_table_update(void){
    int adc_data;
    adc_data = ADC_GetConversion(BAT);
    control_table[voltage_addr] = adc_data;
    control_table[voltage_addr + 1] = adc_data>>8;
    
    int voltage = (adc_data * 5 * 11)/1023;
    if(voltage<=15 && voltage>5){
        control_table[bat_type_addr] = 1;//12Vバッテリ
    }else if(voltage<=30 && voltage>20){
        control_table[bat_type_addr] = 2;//24Vバッテリ
    }else{
        control_table[bat_type_addr] = 0;
    }
    //printf("%d",(control_table[voltage_addr+1]<<8)+control_table[voltage_addr]);
}
