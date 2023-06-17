
#include "mcc_generated_files/system/system.h"

#define ID_addr 1
#define bat_type_addr 2
#define voltage_addr 3
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
    
    __delay_ms(500);
    
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
    printf("Waiting command...\n");
    while(1){
        
        //uart_mode = 0;
        //

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
        
        printf("\n\n");
        printf(buf);
        printf("\ncount num:%d\n",buf_count);
        printf("Waiting command...\n");
        
        
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
    
}
