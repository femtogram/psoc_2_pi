/*******************************************************************************
* File Name: GPIO_4_3.c  
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
#include "GPIO_4_3.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 GPIO_4_3__PORT == 15 && ((GPIO_4_3__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: GPIO_4_3_Write
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
void GPIO_4_3_Write(uint8 value) 
{
    uint8 staticBits = (GPIO_4_3_DR & (uint8)(~GPIO_4_3_MASK));
    GPIO_4_3_DR = staticBits | ((uint8)(value << GPIO_4_3_SHIFT) & GPIO_4_3_MASK);
}


/*******************************************************************************
* Function Name: GPIO_4_3_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  GPIO_4_3_DM_STRONG     Strong Drive 
*  GPIO_4_3_DM_OD_HI      Open Drain, Drives High 
*  GPIO_4_3_DM_OD_LO      Open Drain, Drives Low 
*  GPIO_4_3_DM_RES_UP     Resistive Pull Up 
*  GPIO_4_3_DM_RES_DWN    Resistive Pull Down 
*  GPIO_4_3_DM_RES_UPDWN  Resistive Pull Up/Down 
*  GPIO_4_3_DM_DIG_HIZ    High Impedance Digital 
*  GPIO_4_3_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void GPIO_4_3_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(GPIO_4_3_0, mode);
}


/*******************************************************************************
* Function Name: GPIO_4_3_Read
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
*  Macro GPIO_4_3_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 GPIO_4_3_Read(void) 
{
    return (GPIO_4_3_PS & GPIO_4_3_MASK) >> GPIO_4_3_SHIFT;
}


/*******************************************************************************
* Function Name: GPIO_4_3_ReadDataReg
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
uint8 GPIO_4_3_ReadDataReg(void) 
{
    return (GPIO_4_3_DR & GPIO_4_3_MASK) >> GPIO_4_3_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(GPIO_4_3_INTSTAT) 

    /*******************************************************************************
    * Function Name: GPIO_4_3_ClearInterrupt
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
    uint8 GPIO_4_3_ClearInterrupt(void) 
    {
        return (GPIO_4_3_INTSTAT & GPIO_4_3_MASK) >> GPIO_4_3_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
