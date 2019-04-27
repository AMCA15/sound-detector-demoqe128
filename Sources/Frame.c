/*
 * Frame.c
 *
 *  Created on: Feb 18, 2019
 *  Author: Anderson Contreras
 */

#include "Frame.h"

int CH_Analog[2];
volatile char is_CH_Full;
volatile char *BufferSerialCount;

struct Frame Osc_Frame;
struct Data Channels[2];

void Pack(struct Frame *frame, struct Data *channels) {
	// Byte 0
	frame->DCHA_Ana_Low = channels[CHA].Data_Ana_L;
	frame->DCHA_Dig_Low = channels[CHA].Data_Dig;
	frame->Sync_CHA_Low = 1;
	// Byte 1
	frame->DCHA_Ana_High = channels[CHA].Data_Ana_H;
	frame->DCHA_Dig_High = channels[CHA].Data_Dig;
	frame->Sync_CHA_High = 1;
	// Byte 2
	frame->DCHB_Ana_Low = channels[CHB].Data_Ana_L;
	frame->DCHB_Dig_Low = channels[CHB].Data_Dig;
	frame->Sync_CHB_Low = 1;
	// Byte 3
	frame->DCHB_Ana_High = channels[CHB].Data_Ana_H;
	frame->DCHB_Dig_High = channels[CHB].Data_Dig;
	frame->Sync_CHB_High = 0;
}

