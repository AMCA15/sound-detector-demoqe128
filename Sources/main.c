/* ###################################################################
 **     Filename    : main.c
 **     Project     : Oscilloscope
 **     Processor   : MC9S08QE128CLK
 **     Version     : Driver 01.12
 **     Compiler    : CodeWarrior HCS08 C Compiler
 **     Date/Time   : 2019-02-08, 19:28, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.12
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "AD1.h"
#include "AS1.h"
#include "TI1.h"
#include "Bits1.h"
#include "Bit1.h"
#include "FC1.h"
#include "FilterButton.h"
#include "FilterLED.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Filter.h"
#include "Frame.h"

void main(void) {
	/* Write your local variable definition here */
	char i;

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialisation.                    ***/

	Cpu_EnableInt()
	;

	// Start the continuous conversion, trigger by hardware
	//AD1_Start();

	for (;;) {
		if (is_Data_Ready) {
			if (FilterState == ON) {
				for (i = 0; i < ORDER; i++) {
					FilterOut += coeff[i] * FilterIn[i];
				}
			}
			else
				FilterOut = 255;	// For Testing
		}
		Channels[0].Data_Ana_L = (char) FilterOut;
		Channels[0].Data_Ana_H = (char) ((FilterOut >> 6) | (0x03 & FilterOut));
		Pack(&Osc_Frame, Channels);			// Pack the data
		AS1_SendBlock(&Osc_Frame, OSC_FRAME_SIZE, &BufferSerialCount); // Send the data
		is_Data_Ready = 0;
	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	for (;;) {
	}
	/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
