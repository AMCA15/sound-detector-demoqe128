/* ###################################################################
 **     Filename    : Events.c
 **     Project     : Frame
 **     Processor   : MC9S08QE128CLK
 **     Component   : Events
 **     Version     : Driver 01.02
 **     Compiler    : CodeWarrior HCS08 C Compiler
 **     Date/Time   : 2019-02-08, 19:28, # CodeGen: 0
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file Events.c
 ** @version 01.02
 ** @brief
 **         This is user's event module.
 **         Put your event handler code here.
 */
/*!
 **  @addtogroup Events_module Events module documentation
 **  @{
 */
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Defines.h"
#include "Frame.h"
#include "Filter.h"

/*
 ** ===================================================================
 **     Event       :  AD1_OnEnd (module Events)
 **
 **     Component   :  AD1 [ADC]
 **     Description :
 **         This event is called after the measurement (which consists
 **         of <1 or more conversions>) is/are finished.
 **         The event is available only when the <Interrupt
 **         service/event> property is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void AD1_OnEnd(void) {
	static char i = 0;

	AD1_GetValue(&FilterIn[i]);
	is_Data_Ready = 1;			// Flag for data ready
	Bit1_NegVal();			// For checking sample frequency

	if (i < ORDER)
		i++;
	else
		i = 0;
}

/*
 ** ===================================================================
 **     Event       :  AS1_OnError (module Events)
 **
 **     Component   :  AS1 [AsynchroSerial]
 **     Description :
 **         This event is called when a channel error (not the error
 **         returned by a given method) occurs. The errors can be read
 **         using <GetError> method.
 **         The event is available only when the <Interrupt
 **         service/event> property is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void AS1_OnError(void) {
	/* Write your code here ... */
}

/*
 ** ===================================================================
 **     Event       :  AS1_OnTxChar (module Events)
 **
 **     Component   :  AS1 [AsynchroSerial]
 **     Description :
 **         This event is called after a character is transmitted.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void AS1_OnTxChar(void) {
	/* Write your code here ... */
}

/*
 ** ===================================================================
 **     Event       :  AS1_OnFreeTxBuf (module Events)
 **
 **     Component   :  AS1 [AsynchroSerial]
 **     Description :
 **         This event is called after the last character in output
 **         buffer is transmitted.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void AS1_OnFreeTxBuf(void) {
	/* Write your code here ... */
}

/*
 ** ===================================================================
 **     Event       :  TI1_OnInterrupt (module Events)
 **
 **     Component   :  TI1 [TimerInt]
 **     Description :
 **         When a timer interrupt occurs this event is called (only
 **         when the component is enabled - <Enable> and the events are
 **         enabled - <EnableEvent>). This event is enabled only if a
 **         <interrupt service/event> is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void TI1_OnInterrupt(void) {
	/* Write your code here ... */
	AD1_Measure(0);
}

/*
 ** ===================================================================
 **     Event       :  FilterButton_OnInterrupt (module Events)
 **
 **     Component   :  FilterButton [ExtInt]
 **     Description :
 **         This event is called when an active signal edge/level has
 **         occurred.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void FilterButton_OnInterrupt(void) {
	/* place your FilterButton interrupt procedure body here*/
	if (FilterState == ON) {
		FilterState = OFF;
		FilterLED_ClrVal();
	} else {
		FilterState = ON;
		FilterLED_SetVal();
	}
}

/*
 ** ===================================================================
 **     Event       :  AS1_OnRxCharExt (module Events)
 **
 **     Component   :  AS1 [AsynchroSerial]
 **     Description :
 **         This event is called after a correct character is received.
 **         The last received character is passed as a parameter of the
 **         event function.
 **         Nevertheless, the last received character is placed in the
 **         external buffer of the component.
 **         This event is identical in function with the <OnRxChar>
 **         event with a parameter added. It is not recommended to use
 **         both <OnRxChar> and OnRxCharExt events at the same time.
 **         The event is available only when the <Interrupt
 **         service/event> property is enabled and either the <Receiver>
 **         property is enabled or the <SCI output mode> property (if
 **         supported) is set to Single-wire mode.
 **     Parameters  :
 **         NAME            - DESCRIPTION
 **         Chr             - The last character correctly received.
 **     Returns     : Nothing
 ** ===================================================================
 */
void AS1_OnRxCharExt(AS1_TComData Chr) {
	/* Write your code here ... */
	static char State = IDLE;
	static char i;
	static char Checksum;

	char OpCode = Chr & OPCODEMASK;
	char OpData = Chr & OPDATA;

	if (State == BUSY) {
		if (i < ORDER) {
			NewCoeff[i] = Chr;		 // Save the new coefficients in a temporary buffer for check integrity
			Checksum ^= Chr;		 // before update them
			i++;
		} else {
			if (Checksum == Chr) {   // Only update the coefficients if theirs value are OK
				UpdateCoeff(NewCoeff);
			}
			State = IDLE;			 // Finish the update process
			OpCode = 0;				 // Force to skip the next else in this loop
		}
	}
	else {
		switch (OpCode) {

			case OPCODEBUZZER:
			if (OpData == ON) {
				Buzzer_Enable();
			} else {
				Buzzer_Disable();
			}
			break;

			case OPCODEUPCOEFF:
			State = BUSY;			 // Start the update filter's coefficients process
			Checksum = 0;
			i = 0;
			break;
		}
	}
}


/* END Events */

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
