
#include "mcc_generated_files/system/system.h"

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();

    INTERRUPT_GlobalInterruptEnable(); 
    INTERRUPT_PeripheralInterruptEnable();
    
    
    LED_PD_SetHigh();


    while(1)
    {
        if(SW_bit3_PORT == 1){
            LED_R_SetHigh();     
        }else{
            LED_R_SetLow();
        }
        
        if(SW_bit2_PORT == 1){
            LED_Y_SetHigh();     
        }else{
            LED_Y_SetLow();
        }
        
        if(SW_bit1_PORT == 1){
            LED_G_SetHigh();     
        }else{
            LED_G_SetLow();
        }
        
        
        
        __delay_ms(10);
    }    
}