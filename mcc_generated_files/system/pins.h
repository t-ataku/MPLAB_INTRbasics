/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver Pins Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *
 * @skipline @version   Firmware Driver Version 1.0.2
 *
 * @skipline @version   PLIB Version 1.4.2
 *
 * @skipline  Device : dsPIC33CK64MC105
*/

/*
? [2026] Microchip Technology Inc. and its subsidiaries.

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

#ifdef __cplusplus
extern "C" {
#endif

// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD10 GPIO Pin which has a custom name of IO_LED to High
 * @pre      The RD10 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_LED_SetHigh()          (_LATD10 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD10 GPIO Pin which has a custom name of IO_LED to Low
 * @pre      The RD10 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_LED_SetLow()           (_LATD10 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RD10 GPIO Pin which has a custom name of IO_LED
 * @pre      The RD10 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_LED_Toggle()           (_LATD10 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RD10 GPIO Pin which has a custom name of IO_LED
 * @param    none
 * @return   none  
 */
#define IO_LED_GetValue()         _RD10

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD10 GPIO Pin which has a custom name of IO_LED as Input
 * @param    none
 * @return   none  
 */
#define IO_LED_SetDigitalInput()  (_TRISD10 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD10 GPIO Pin which has a custom name of IO_LED as Output
 * @param    none
 * @return   none  
 */
#define IO_LED_SetDigitalOutput() (_TRISD10 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD13 GPIO Pin which has a custom name of IO_SW to High
 * @pre      The RD13 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_SW_SetHigh()          (_LATD13 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD13 GPIO Pin which has a custom name of IO_SW to Low
 * @pre      The RD13 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_SW_SetLow()           (_LATD13 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RD13 GPIO Pin which has a custom name of IO_SW
 * @pre      The RD13 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_SW_Toggle()           (_LATD13 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RD13 GPIO Pin which has a custom name of IO_SW
 * @param    none
 * @return   none  
 */
#define IO_SW_GetValue()         _RD13

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD13 GPIO Pin which has a custom name of IO_SW as Input
 * @param    none
 * @return   none  
 */
#define IO_SW_SetDigitalInput()  (_TRISD13 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD13 GPIO Pin which has a custom name of IO_SW as Output
 * @param    none
 * @return   none  
 */
#define IO_SW_SetDigitalOutput() (_TRISD13 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);

/**
 * @ingroup  pinsdriver
 * @brief    This function is callback for IO_SW Pin
 * @param    none
 * @return   none   
 */
void IO_SW_CallBack(void);


/**
 * @ingroup    pinsdriver
 * @brief      This function assigns a function pointer with a callback address
 * @param[in]  InterruptHandler - Address of the callback function 
 * @return     none  
 */
void IO_SW_SetInterruptHandler(void (* InterruptHandler)(void));


#ifdef __cplusplus
}
#endif

#endif
