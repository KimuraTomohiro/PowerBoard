
#include "mcc_generated_files/system/system.h"
#include <string.h>
#include <ctype.h>

#define ID_addr 1
#define bat_type_addr 2
#define voltage_addr 3//3が下位ビット４が上位ビット
#define output_addr 5
#define HES_status_addr 6


unsigned char control_table[20] = {0xFF};
void init(void);
void putch(unsigned char Data);
void control_table_update(void);
void RS485master_mode(void);
void RS485slave_mode(void);
void RS485_Send(char ID,char adress,char type,char data1,char data2);
char *RS485_Receive();
void timeout_flug_maker(void);
char timeout_flug = 0;
unsigned char buf[50]; 
char RS485_buf[7]={0};
char init_flug =0;
char past_massage = 0;




int main(void)
{
    SYSTEM_Initialize();

    INTERRUPT_GlobalInterruptEnable(); 
    INTERRUPT_PeripheralInterruptEnable();
    Timer0_OverflowCallbackRegister(control_table_update);
    Timer1_OverflowCallbackRegister(timeout_flug_maker);
    Timer1_Stop();
    
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

        while(!EUSART2_IsTxReady());
        EUSART2_Write(Data);
        while(!EUSART2_IsTxDone());

    
 
return;
}
///*
void RS485master_mode(void){
    

    
    while(1){
        
        //uart_mode = 0;
        //
    printf("Waiting command...\n");
        
//    if(HES_flug == 1){
//        control_table[output_addr] = 0;
//        for(char i=1;i<7;i++){
//            RS485_Send(i,output_addr,0x01,0x00,0xFF);
//        }
//    }
//    
    
    
    
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
                printf("Turn ON Board %d\n\n",buf[3] - '0');
                //実行用コマンド書く
                //数字から’０’を引くことで数値に変換できる
                if(buf[3]-'0'==0){
                    
                    control_table[output_addr] = 1;
                    
                }else{
                    for(char k=0;k<3;k++){
                        RS485_Send(buf[3]-'0',output_addr,0x01,0x01,0xFF);
                        __delay_us(10);
                    }
                    
                }
            }else{
                printf("Irregular Board num\n\n");
            }
            
        }
        
        else if(strncmp(buf,"OFF", strlen("OFF")) == 0){
            if(isdigit(buf[4]) == 1){ 
                printf("Turn OFF Board %d\n\n",buf[4] - '0');
                //実行用コマンド書く
                //数字から’０’を引くことで数値に変換できる
                if(buf[4]-'0'==0){
                    //SE_SetLow();
                    control_table[output_addr] = 0;
                   //
                    LED_R_SetLow();
                
                }else{
                    for(char k=0;k<3;k++){
                        RS485_Send(buf[4]-'0',output_addr,0x01,0x00,0xFF);
                        __delay_us(10);
                    }
                }
                
            }else{
                printf("Irregular Board num\n\n");
            }
            
        }else if(strncmp(buf,"GETV", strlen("GETV")) == 0){
            if(isdigit(buf[5]) == 1){
                
                printf("Board %d: ",buf[5] - '0');
                double voltage;
                timeout_flug = 0;
                if(buf[5]-'0'==0){
                    voltage = (double)((control_table[voltage_addr+1]<<8)+control_table[voltage_addr])/1023 * 5.04 * 11;
                }else{
                    RS485_Send(buf[5]-'0',voltage_addr,0x00,0xFF,0xFF);
                    char *voltage_buf = RS485_Receive();
                    
                printf("buf: %d %d %d %d %d %d %d %d\n\n",voltage_buf[0],voltage_buf[1],voltage_buf[2],voltage_buf[3],voltage_buf[4],voltage_buf[5],voltage_buf[6],voltage_buf[7],voltage_buf[8]);

                    voltage = (double)((voltage_buf[5]<<8)+control_table[4])/1023 * 5.04 * 11;
                    
                    
                    
                }
                if(timeout_flug == 0){
                    printf("%d.",(int)voltage);
                    printf("%d\n\n",(int)(10*(voltage - (int)voltage)));
                }else{
                    printf("Error\n\n");
                }
            }else{
                printf("Irregular Board num\n\n");
            }
            
            
//        }else if(strncmp(buf,"VOFFSET", strlen("VOFFSET")) == 0){
//            if(isdigit(buf[8]) == 1){ 
//                printf("OK Input Offset * 100\n");
//                for(int i=0; i<50; i++){
//                buf[i] = 0;
//                }
//                
//                do{
//                    while(EUSART2_IsRxReady() == false);
//                    buf[buf_count] = EUSART2_Read();
//
//                    buf_count++;
//
//                    if(buf_count >= 50){
//                        break;
//                    }
//           
//                }while(buf[buf_count - 1] != '-');
//                
//                double offset=0;
//                switch(strlen(buf)){
//                    case 1:
//                        offset = (buf[0]-'0')/100.0;
//                        break;
//                       
//                    case 2:
//                        offset = (buf[0]-'0')/10.0 + (buf[1]-'0')/100.0;
//                        break;
//                        
//                    case 3:
//                        offset = (buf[0]-'0') + (buf[1]-'0')/10.0+ (buf[2]-'0')/100.0;
//                        break;
//                              
//                }
//                  
//            }else{
//                printf("Irregular Board num\n\n");
//            }
//            
//            
//            
        }else{
            printf("Irregular command\n\n");
        }
        
        //ここまでコマンド処理
        for(int i=0; i<50; i++){
            buf[i] = 0;
        }
        
        
        
        
    }
    
}
//   */ 
 
void RS485slave_mode(void){
    char *get_buf = {0};
    while(1){
        //printf("Waiting\n");
        while(EUSART1_IsRxReady() == false);
        
        get_buf = RS485_Receive();
        
        //printf("buf: %X %X %X %X %X %X %X\n",get_buf[0],get_buf[1],get_buf[2],get_buf[3],get_buf[4],get_buf[5],get_buf[6]); 
        //printf("ID: %d",control_table[ID_addr]);
        
        if(get_buf[2] == control_table[ID_addr]){
            //printf("ID clear");
            if(get_buf[4]== 1){
                //書き込み命令の際
                control_table[get_buf[3]]=get_buf[5];
            }else if(get_buf[4] == 0){
                __delay_ms(1);
                RS485_Send(0,get_buf[3],0,control_table[get_buf[3]],control_table[get_buf[3]+1]);
            }
        }
       // printf("OK\n");
        
    }
    }
    


void init(void){
    RS485_SW_SetLow();
    LED_PD_SetHigh();
    
    SE_SetLow();
    
    control_table[ID_addr] = SW_bit1_PORT + SW_bit2_PORT * 2 + SW_bit3_PORT * 4;
    
    init_flug = 1;
    
//    control_table[voltage_offset_addr] = FLASH_Read(6);
//    if(control_table[voltage_offset_addr] == 0xFF){
//        control_table[voltage_offset_addr] = 0;
//    }
    

    printf("\n\nSystem Initialized\n");
    __delay_ms(10);
}

void control_table_update(void){
    
    if(init_flug != 1)
        return;
    
    
    int adc_data;
    adc_data = ADC_GetConversion(BAT);
    control_table[voltage_addr] = adc_data;
    control_table[voltage_addr + 1] = adc_data>>8;
    
    double voltage = (adc_data * 5 * 11)/1023.0;
    if(voltage<=15 && voltage>5){
        control_table[bat_type_addr] = 1;//12Vバッテリ
    }else if(voltage<=30 && voltage>18){
        control_table[bat_type_addr] = 2;//24Vバッテリ
    }else{
        control_table[bat_type_addr] = 0;
    }
    
    if(control_table[ID_addr] == 0){
        if(HES_PORT == 0 && past_massage != 0x01){
            control_table[HES_status_addr] = 1;
            for(char i=1;i<7;i++){
                for(char k=0;k<5;k++){
                    RS485_Send(i,HES_status_addr,0x01,0x01,0xFF);
                }
                past_massage = 0x01;
            }
        }else if(HES_PORT == 1 && past_massage != 0x00){
            control_table[HES_status_addr] = 0;
            for(char i=1;i<7;i++){
                for(char k=0;k<5;k++){
                    RS485_Send(i,HES_status_addr,0x01,0x00,0xFF);
                }
                past_massage = 0x00;
            }
        }
    }
    
    if(control_table[output_addr] == 1 && control_table[HES_status_addr] == 0){
        SE_SetHigh();
        LED_R_SetHigh();
    }else{
        SE_SetLow();
        LED_R_SetLow();
    }
    
    switch(control_table[bat_type_addr]){
        case 1:
            if(voltage>11.5){
                LED_G_SetHigh();
                LED_Y_SetLow();
                
            }else if(voltage<=11.5 && voltage>10){
                LED_G_SetLow();
                LED_Y_SetHigh();
                
            }else{
                LED_G_SetLow();
                LED_Y_SetLow();
                
            }
            break;
            
        case 2:
            if(voltage>23.5){
                LED_G_SetHigh();
                LED_Y_SetLow();
                
            }else if(voltage<=23.5 && voltage>20){
                LED_G_SetLow();
                LED_Y_SetHigh();
                
            }else{
                LED_G_SetLow();
                LED_Y_SetLow();
                
            }
            break;
            
        case 3:
                LED_G_SetLow();
                LED_Y_SetLow();
                
                break;
            
            
    }
    //printf("%d",(control_table[voltage_addr+1]<<8)+control_table[voltage_addr]);
}


void RS485_Send(char ID,char adress,char type,char data1,char data2){
    
    RS485_SW_SetHigh();
    while(EUSART1_IsTxReady() == 0);
        EUSART1_Write(0xFF);
    while(!EUSART1_IsTxDone());
        EUSART1_Write(0xFF);
    while(!EUSART1_IsTxDone());
        EUSART1_Write(ID);
    while(!EUSART1_IsTxDone());
        EUSART1_Write(adress);
    while(!EUSART1_IsTxDone());
        EUSART1_Write(type);    //書き込みなら１、読み出しなら０
    while(!EUSART1_IsTxDone());
        EUSART1_Write(data1);
    while(!EUSART1_IsTxDone());
        EUSART1_Write(data2);   //使わない場合は0xFF
    RS485_SW_SetLow();
}


char *RS485_Receive(){
    for(int t=0;t<7;t++){
        RS485_buf[t] = 0;
    }
    
    timeout_flug = 0;
    Timer1_Start();
    
    while(EUSART1_IsRxReady() == false){
        
        if(timeout_flug == 1){
            for(int t=0;t<7;t++){
            RS485_buf[t] = 0;
            return RS485_buf;
            }
        }
            
    }
    for(char i = 0;i<7; i++){
//        printf("OK");
        while(EUSART1_IsRxReady() == false){
        if(timeout_flug == 1){
            for(int t=0;t<7;t++){
            RS485_buf[t] = 0;
            return RS485_buf;
                }   
            }
        }
        RS485_buf[i] = EUSART1_Read();
    }

    return RS485_buf;
}


void timeout_flug_maker(void){
    timeout_flug = 1;
    Timer1_Stop();
    Timer1_Write(0);
}