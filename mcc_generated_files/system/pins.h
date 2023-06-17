/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA0 aliases
#define SW_TRIS                 TRISAbits.TRISA0
#define SW_LAT                  LATAbits.LATA0
#define SW_PORT                 PORTAbits.RA0
#define SW_WPU                  WPUAbits.WPUA0
#define SW_OD                   ODCONAbits.ODCA0
#define SW_ANS                  ANSELAbits.ANSA0
#define SW_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SW_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SW_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SW_GetValue()           PORTAbits.RA0
#define SW_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SW_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SW_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SW_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SW_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define SW_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define SW_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SW_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)
// get/set IO_RA1 aliases
#define HES_TRIS                 TRISAbits.TRISA1
#define HES_LAT                  LATAbits.LATA1
#define HES_PORT                 PORTAbits.RA1
#define HES_WPU                  WPUAbits.WPUA1
#define HES_OD                   ODCONAbits.ODCA1
#define HES_ANS                  ANSELAbits.ANSA1
#define HES_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define HES_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define HES_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define HES_GetValue()           PORTAbits.RA1
#define HES_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define HES_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define HES_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define HES_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define HES_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define HES_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define HES_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define HES_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)
#define RA1_SetInterruptHandler  HES_SetInterruptHandler
// get/set IO_RB2 aliases
#define BAT_TRIS                 TRISBbits.TRISB2
#define BAT_LAT                  LATBbits.LATB2
#define BAT_PORT                 PORTBbits.RB2
#define BAT_WPU                  WPUBbits.WPUB2
#define BAT_OD                   ODCONBbits.ODCB2
#define BAT_ANS                  ANSELBbits.ANSB2
#define BAT_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BAT_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BAT_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BAT_GetValue()           PORTBbits.RB2
#define BAT_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BAT_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BAT_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BAT_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BAT_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define BAT_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define BAT_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define BAT_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)
// get/set IO_RB3 aliases
#define SW_bit3_TRIS                 TRISBbits.TRISB3
#define SW_bit3_LAT                  LATBbits.LATB3
#define SW_bit3_PORT                 PORTBbits.RB3
#define SW_bit3_WPU                  WPUBbits.WPUB3
#define SW_bit3_OD                   ODCONBbits.ODCB3
#define SW_bit3_ANS                  ANSELBbits.ANSB3
#define SW_bit3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SW_bit3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SW_bit3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SW_bit3_GetValue()           PORTBbits.RB3
#define SW_bit3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SW_bit3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SW_bit3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SW_bit3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SW_bit3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SW_bit3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SW_bit3_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define SW_bit3_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)
// get/set IO_RB4 aliases
#define SW_bit2_TRIS                 TRISBbits.TRISB4
#define SW_bit2_LAT                  LATBbits.LATB4
#define SW_bit2_PORT                 PORTBbits.RB4
#define SW_bit2_WPU                  WPUBbits.WPUB4
#define SW_bit2_OD                   ODCONBbits.ODCB4
#define SW_bit2_ANS                  ANSELBbits.ANSB4
#define SW_bit2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SW_bit2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SW_bit2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SW_bit2_GetValue()           PORTBbits.RB4
#define SW_bit2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SW_bit2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SW_bit2_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SW_bit2_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SW_bit2_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SW_bit2_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SW_bit2_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SW_bit2_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define SW_bit1_TRIS                 TRISBbits.TRISB5
#define SW_bit1_LAT                  LATBbits.LATB5
#define SW_bit1_PORT                 PORTBbits.RB5
#define SW_bit1_WPU                  WPUBbits.WPUB5
#define SW_bit1_OD                   ODCONBbits.ODCB5
#define SW_bit1_ANS                  ANSELBbits.ANSB5
#define SW_bit1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SW_bit1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SW_bit1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SW_bit1_GetValue()           PORTBbits.RB5
#define SW_bit1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SW_bit1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SW_bit1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SW_bit1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SW_bit1_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SW_bit1_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SW_bit1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define SW_bit1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)
// get/set IO_RB6 aliases
#define PC_TX_TRIS                 TRISBbits.TRISB6
#define PC_TX_LAT                  LATBbits.LATB6
#define PC_TX_PORT                 PORTBbits.RB6
#define PC_TX_WPU                  WPUBbits.WPUB6
#define PC_TX_OD                   ODCONBbits.ODCB6
#define PC_TX_ANS                  ANSELBbits.ANSB6
#define PC_TX_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define PC_TX_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define PC_TX_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define PC_TX_GetValue()           PORTBbits.RB6
#define PC_TX_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define PC_TX_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define PC_TX_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define PC_TX_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define PC_TX_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define PC_TX_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define PC_TX_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define PC_TX_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)
// get/set IO_RB7 aliases
#define PC_RX_TRIS                 TRISBbits.TRISB7
#define PC_RX_LAT                  LATBbits.LATB7
#define PC_RX_PORT                 PORTBbits.RB7
#define PC_RX_WPU                  WPUBbits.WPUB7
#define PC_RX_OD                   ODCONBbits.ODCB7
#define PC_RX_ANS                  ANSELBbits.ANSB7
#define PC_RX_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define PC_RX_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define PC_RX_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define PC_RX_GetValue()           PORTBbits.RB7
#define PC_RX_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define PC_RX_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define PC_RX_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define PC_RX_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define PC_RX_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define PC_RX_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define PC_RX_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define PC_RX_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)
// get/set IO_RC0 aliases
#define LED_PD_TRIS                 TRISCbits.TRISC0
#define LED_PD_LAT                  LATCbits.LATC0
#define LED_PD_PORT                 PORTCbits.RC0
#define LED_PD_WPU                  WPUCbits.WPUC0
#define LED_PD_OD                   ODCONCbits.ODCC0
#define LED_PD_ANS                  ANSELCbits.ANSC0
#define LED_PD_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED_PD_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LED_PD_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LED_PD_GetValue()           PORTCbits.RC0
#define LED_PD_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LED_PD_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LED_PD_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define LED_PD_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define LED_PD_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define LED_PD_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define LED_PD_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define LED_PD_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)
// get/set IO_RC1 aliases
#define LED_G_TRIS                 TRISCbits.TRISC1
#define LED_G_LAT                  LATCbits.LATC1
#define LED_G_PORT                 PORTCbits.RC1
#define LED_G_WPU                  WPUCbits.WPUC1
#define LED_G_OD                   ODCONCbits.ODCC1
#define LED_G_ANS                  ANSELCbits.ANSC1
#define LED_G_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LED_G_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LED_G_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LED_G_GetValue()           PORTCbits.RC1
#define LED_G_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LED_G_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LED_G_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LED_G_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LED_G_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define LED_G_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define LED_G_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define LED_G_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)
// get/set IO_RC2 aliases
#define LED_Y_TRIS                 TRISCbits.TRISC2
#define LED_Y_LAT                  LATCbits.LATC2
#define LED_Y_PORT                 PORTCbits.RC2
#define LED_Y_WPU                  WPUCbits.WPUC2
#define LED_Y_OD                   ODCONCbits.ODCC2
#define LED_Y_ANS                  ANSELCbits.ANSC2
#define LED_Y_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED_Y_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED_Y_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED_Y_GetValue()           PORTCbits.RC2
#define LED_Y_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED_Y_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LED_Y_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LED_Y_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LED_Y_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LED_Y_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LED_Y_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LED_Y_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define LED_R_TRIS                 TRISCbits.TRISC3
#define LED_R_LAT                  LATCbits.LATC3
#define LED_R_PORT                 PORTCbits.RC3
#define LED_R_WPU                  WPUCbits.WPUC3
#define LED_R_OD                   ODCONCbits.ODCC3
#define LED_R_ANS                  ANSELCbits.ANSC3
#define LED_R_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED_R_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED_R_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED_R_GetValue()           PORTCbits.RC3
#define LED_R_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED_R_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED_R_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LED_R_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LED_R_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LED_R_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LED_R_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LED_R_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC5 aliases
#define RS485_SW_TRIS                 TRISCbits.TRISC5
#define RS485_SW_LAT                  LATCbits.LATC5
#define RS485_SW_PORT                 PORTCbits.RC5
#define RS485_SW_WPU                  WPUCbits.WPUC5
#define RS485_SW_OD                   ODCONCbits.ODCC5
#define RS485_SW_ANS                  ANSELCbits.ANSC5
#define RS485_SW_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RS485_SW_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RS485_SW_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RS485_SW_GetValue()           PORTCbits.RC5
#define RS485_SW_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RS485_SW_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RS485_SW_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define RS485_SW_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define RS485_SW_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define RS485_SW_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define RS485_SW_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define RS485_SW_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)
// get/set IO_RC6 aliases
#define RS485_TX_TRIS                 TRISCbits.TRISC6
#define RS485_TX_LAT                  LATCbits.LATC6
#define RS485_TX_PORT                 PORTCbits.RC6
#define RS485_TX_WPU                  WPUCbits.WPUC6
#define RS485_TX_OD                   ODCONCbits.ODCC6
#define RS485_TX_ANS                  ANSELCbits.ANSC6
#define RS485_TX_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RS485_TX_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RS485_TX_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RS485_TX_GetValue()           PORTCbits.RC6
#define RS485_TX_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RS485_TX_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RS485_TX_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define RS485_TX_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define RS485_TX_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define RS485_TX_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define RS485_TX_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define RS485_TX_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)
// get/set IO_RC7 aliases
#define RS485_RX_TRIS                 TRISCbits.TRISC7
#define RS485_RX_LAT                  LATCbits.LATC7
#define RS485_RX_PORT                 PORTCbits.RC7
#define RS485_RX_WPU                  WPUCbits.WPUC7
#define RS485_RX_OD                   ODCONCbits.ODCC7
#define RS485_RX_ANS                  ANSELCbits.ANSC7
#define RS485_RX_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RS485_RX_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RS485_RX_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RS485_RX_GetValue()           PORTCbits.RC7
#define RS485_RX_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RS485_RX_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RS485_RX_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define RS485_RX_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define RS485_RX_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define RS485_RX_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define RS485_RX_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define RS485_RX_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the HES pin functionality
 * @param none
 * @return none
 */
void HES_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for HES pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for HES at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void HES_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for HES pin.
 *        This is a dynamic interrupt handler to be used together with the HES_SetInterruptHandler() method.
 *        This handler is called every time the HES ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*HES_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for HES pin. 
 *        This is a predefined interrupt handler to be used together with the HES_SetInterruptHandler() method.
 *        This handler is called every time the HES ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void HES_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/