/*
 * Frame.h
 *
 *  Created on: Feb 18, 2019
 *  Author: Anderson Contreras
 */

#ifndef FRAME_H_
#define FRAME_H_

#include "PE_Types.h"

#define CHA 0
#define CHB 1
#define OSC_FRAME_SIZE 4

extern volatile char is_Data_Ready;
extern volatile char *BufferSerialCount;

// Data struct for channels (Digitals & Analogs)
struct Data {
	word Data_Ana_H :6;
	word Data_Ana_L :6;
	word Data_Dig :1;
};
extern struct Data Channels[2];

// Data frame struct
struct Frame {
	byte DCHA_Ana_Low :6;
	byte DCHA_Dig_Low :1;
	byte Sync_CHA_Low :1;
	byte DCHA_Ana_High :6;
	byte DCHA_Dig_High :1;
	byte Sync_CHA_High :1;
	byte DCHB_Ana_Low :6;
	byte DCHB_Dig_Low :1;
	byte Sync_CHB_Low :1;
	byte DCHB_Ana_High :6;
	byte DCHB_Dig_High :1;
	byte Sync_CHB_High :1;
};
extern struct Frame Osc_Frame;

// Function for packing the data
void Pack(struct Frame *frame, struct Data *channels);

#endif /* FRAME_H_ */
