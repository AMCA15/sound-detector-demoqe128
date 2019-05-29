/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : FC1.h
**     Project     : Oscilloscope
**     Processor   : MC9S08QE128CLK
**     Component   : FreeCntr
**     Version     : Component 01.118, Driver 01.13, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2019-05-29, 11:22, # CodeGen: 0
**     Abstract    :
**         This device "FreeCntr" implements a free running counter for
**         time measurement.
**     Settings    :
**         Timer name                  : RTC (8-bit)
**         Compare name                : RTCmod
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 32768 Hz
**           Period
**             Xtal ticks              : 16
**             microseconds            : 488
**             seconds (real)          : 0.00048828125
**             Hz                      : 2048
**             kHz                     : 2
**           Frequency of counting (Bus clock / prescaler)
**             Hz                      : 32768
**
**         Initialization:
**              Timer                  : Enabled
**
**         Timer registers
**              Counter                : RTCCNT    [$1831]
**              Mode                   : RTCSC     [$1830]
**              Run                    : RTCSC     [$1830]
**              Prescaler              : RTCSC     [$1830]
**              Compare                : RTCMOD    [$1832]
**
**         User handling procedure     : not specified
**     Contents    :
**         Reset           - byte FC1_Reset(void);
**         GetCounterValue - byte FC1_GetCounterValue(FC1_TTimerValue *Value);
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
** @file FC1.h
** @version 01.13
** @brief
**         This device "FreeCntr" implements a free running counter for
**         time measurement.
*/         
/*!
**  @addtogroup FC1_module FC1 module documentation
**  @{
*/         

#ifndef __FC1
#define __FC1

/* MODULE FC1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited components */
#include "Cpu.h"

/* PUBLISHED CONSTANTS */
#define FC1_COUNTER_INPUT_CLOCK_HZ    0x8000UL /* Initial counter input clock frequency [Hz] */
#define FC1_PERIOD_VALUE              0x10UL /* Initial period value in ticks of the timer */
#define FC1_PRESCALER_VALUE           0x01U /* Prescaler value of the timer in high speed mode */
#define FC1_TIMER_INPUT_CLOCK         0x8000UL /* Deprecated, Initial timer input clock value [Hz] */
#define FC1_UP_COUNTER                1 /* The timer counts upwards */
#define FC1_RESET_ON_COMPARE          1 /* Property "Reset on compare" selected */
/* High speed mode constants */
#define FC1_COUNTER_INPUT_CLOCK_HZ_HIGH 0x8000UL /* Counter input clock frequency in high speed mode [Hz] */
#define FC1_PERIOD_VALUE_HIGH         0x10UL /* Period value in ticks of the timer in high speed mode */
#define FC1_PRESCALER_VALUE_HIGH      0x01U /* Prescaler value of the timer in high speed mode */
#define FC1_TIMER_INPUT_CLOCK_HIGH    0x8000UL /* Deprecated, Initial timer input clock value [Hz] */

typedef byte FC1_TTimerValue;          /* Counter or compare value, width depends on timer width */

#define FC1_Reset() ( \
  RTCMOD = RTCMOD,                     /* Reset HW Counter */ \
  (byte)ERR_OK                         /* Return result */ \
)
/*
** ===================================================================
**     Method      :  FC1_Reset (component FreeCntr)
*/
/*!
**     @brief
**         This method resets the timer-counter (sets to zero for
**         up-counting HW or to appropriate value for down-counting HW).
**         The method is available only if the counter register can be
**         set by software and the counter is not shared.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
*/
/* ===================================================================*/

#define FC1_GetCounterValue(Value) ( \
  *(Value) = RTCCNT,                   /* Set the flag "events disabled" */ \
  (byte)ERR_OK                         /* Return result */ \
)
/*
** ===================================================================
**     Method      :  FC1_GetCounterValue (component FreeCntr)
*/
/*!
**     @brief
**         This method returns a content of the counter.
**     @param
**         Value           - Pointer to returned value.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
*/
/* ===================================================================*/

void FC1_Init(void);
/*
** ===================================================================
**     Method      :  FC1_Init (component FreeCntr)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END FC1. */

#endif /* ifndef __FC1 */
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
