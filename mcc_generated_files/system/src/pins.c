 /**
 * PINS Generated Driver Source File 
 * 
 * @file      pins.c
 *            
 * @ingroup   pinsdriver
 *            
 * @brief     This is the generated driver source file for PINS driver.
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

// Section: Includes
#include <xc.h>
#include <stddef.h>
#include "../pins.h"

// Section: File specific functions
static void (*IO_SW_InterruptHandler)(void) = NULL;

// Section: Driver Interface Function Definitions
void PINS_Initialize(void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000U;
    LATB = 0x0000U;
    LATC = 0x0000U;
    LATD = 0x0000U;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x001FU;
    TRISB = 0xFFFFU;
    TRISC = 0x3FFFU;
    TRISD = 0x2102U;


    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPUA = 0x0000U;
    CNPUB = 0x0000U;
    CNPUC = 0x0000U;
    CNPUD = 0x2000U;
    CNPDA = 0x0000U;
    CNPDB = 0x0000U;
    CNPDC = 0x0000U;
    CNPDD = 0x0000U;


    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000U;
    ODCB = 0x0000U;
    ODCC = 0x0000U;
    ODCD = 0x0000U;


    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x001FU;
    ANSELB = 0x039FU;
    ANSELC = 0x00CFU;
    ANSELD = 0x0000U;
    /*******************************************************************************
    * Interrupt On Change: any
    *******************************************************************************/
    CNEN0Dbits.CNEN0D13 = 1; //Pin : RD13U; 
    CNEN1Dbits.CNEN1D13 = 1; //Pin : RD13U; 

    /****************************************************************************
     * Interrupt On Change: flag
     ***************************************************************************/
    CNFDbits.CNFD13 = 0;    //Pin : IO_SW

    /****************************************************************************
     * Interrupt On Change: config
     ***************************************************************************/
    CNCONDbits.CNSTYLE = 1; //Config for PORTD
    CNCONDbits.ON = 1; //Config for PORTD

    /* Initialize IOC Interrupt Handler*/
    IO_SW_SetInterruptHandler(&IO_SW_CallBack);

    /****************************************************************************
     * Interrupt On Change: Interrupt Enable
     ***************************************************************************/
    IFS4bits.CNDIF = 0; //Clear CNDI interrupt flag
    IEC4bits.CNDIE = 1; //Enable CNDI interrupt
}

void __attribute__ ((weak)) IO_SW_CallBack(void)
{

}

void IO_SW_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC4bits.CNDIE = 0; //Disable CNDI interrupt
    IO_SW_InterruptHandler = InterruptHandler; 
    IEC4bits.CNDIE = 1; //Enable CNDI interrupt
}

/* Interrupt service function for the CNDI interrupt. */
/* cppcheck-suppress misra-c2012-8.4
*
* (Rule 8.4) REQUIRED: A compatible declaration shall be visible when an object or 
* function with external linkage is defined
*
* Reasoning: Interrupt declaration are provided by compiler and are available
* outside the driver folder
*/
void __attribute__ (( interrupt, no_auto_psv )) _CNDInterrupt (void)
{
    if(CNFDbits.CNFD13 == 1)
    {
        if(IO_SW_InterruptHandler != NULL) 
        { 
            IO_SW_InterruptHandler(); 
        }
        
        CNFDbits.CNFD13 = 0;  //Clear flag for Pin - IO_SW
    }
    
    // Clear the flag
    IFS4bits.CNDIF = 0;
}

