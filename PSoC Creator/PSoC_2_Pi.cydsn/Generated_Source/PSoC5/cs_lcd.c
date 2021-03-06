/*******************************************************************************
* File Name: cs_lcd.c  
* Version 2.0
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "cs_lcd.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 cs_lcd__PORT == 15 && ((cs_lcd__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: cs_lcd_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void cs_lcd_Write(uint8 value) 
{
    uint8 staticBits = (cs_lcd_DR & (uint8)(~cs_lcd_MASK));
    cs_lcd_DR = staticBits | ((uint8)(value << cs_lcd_SHIFT) & cs_lcd_MASK);
}


/*******************************************************************************
* Function Name: cs_lcd_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  cs_lcd_DM_STRONG     Strong Drive 
*  cs_lcd_DM_OD_HI      Open Drain, Drives High 
*  cs_lcd_DM_OD_LO      Open Drain, Drives Low 
*  cs_lcd_DM_RES_UP     Resistive Pull Up 
*  cs_lcd_DM_RES_DWN    Resistive Pull Down 
*  cs_lcd_DM_RES_UPDWN  Resistive Pull Up/Down 
*  cs_lcd_DM_DIG_HIZ    High Impedance Digital 
*  cs_lcd_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void cs_lcd_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(cs_lcd_0, mode);
}


/*******************************************************************************
* Function Name: cs_lcd_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro cs_lcd_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 cs_lcd_Read(void) 
{
    return (cs_lcd_PS & cs_lcd_MASK) >> cs_lcd_SHIFT;
}


/*******************************************************************************
* Function Name: cs_lcd_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 cs_lcd_ReadDataReg(void) 
{
    return (cs_lcd_DR & cs_lcd_MASK) >> cs_lcd_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(cs_lcd_INTSTAT) 

    /*******************************************************************************
    * Function Name: cs_lcd_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 cs_lcd_ClearInterrupt(void) 
    {
        return (cs_lcd_INTSTAT & cs_lcd_MASK) >> cs_lcd_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
