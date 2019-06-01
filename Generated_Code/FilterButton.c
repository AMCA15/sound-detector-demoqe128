/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : FilterButton.c
**     Project     : sound-detector-demoqe128
**     Processor   : MC9S08QE128CLK
**     Component   : ExtInt
**     Version     : Component 02.105, Driver 01.24, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2019-05-31, 20:55, # CodeGen: 63
**     Abstract    :
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**         Interrupt name              : Vkeyboard
**         User handling procedure     : FilterButton_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       60            |  PTA2_KBI1P2_SDA1_ADP2
**             ----------------------------------------------------
**
**         Port name                   : PTA
**
**         Bit number (in port)        : 2
**         Bit mask of the port        : $0004
**
**         Signal edge/level           : falling
**         Priority                    : 
**         Pull option                 : up
**         Initial state               : Enabled
**
**
**         Port data register          : PTAD      [$0000]
**         Port control register       : PTADD     [$0001]
**     Contents    :
**         GetVal - bool FilterButton_GetVal(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file FilterButton.c
** @version 01.24
** @brief
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
*/         
/*!
**  @addtogroup FilterButton_module FilterButton module documentation
**  @{
*/         

#include "FilterButton.h"

/*Including shared modules, which are used for all project*/

#include "Events.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  FilterButton_Interrupt (component ExtInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the components event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(FilterButton_Interrupt)
{
  KBI1SC_KBACK = 1U;                   /* Clear the interrupt flag */
  FilterButton_OnInterrupt();          /* Invoke user event */
}

/*
** ===================================================================
**     Method      :  FilterButton_GetVal (component ExtInt)
**     Description :
**         Returns the actual value of the input pin of the component.
**     Parameters  : None
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           <false> - logical "0" (Low level) <true> -
**                           logical "1" (High level)
** ===================================================================
*/
/*
bool FilterButton_GetVal(void)

**      This method is implemented as macro. See FilterButton.h file.      **
*/

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
