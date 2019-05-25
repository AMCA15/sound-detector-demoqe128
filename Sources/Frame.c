/*
 * Frame.c
 *
 *  Created on: Feb 18, 2019
 *  Author: Anderson Contreras
 */

#include "Frame.h"

volatile char is_Data_Ready;
volatile char *BufferSerialCount;

struct FRAME Frame;
struct DATA Data;

void Pack(struct FRAME *frame, struct DATA data) {
    // Byte 0
    frame->Ana_low  = data.Analog.halfbyte.low;
    frame->Syn_low  = 1;
    // Byte 1
    frame->Ana_high = data.Analog.halfbyte.high;
    frame->Dig_1    = data.Digital.sensor1;
    frame->Dig_2    = data.Digital.sensor2;
    frame->Syn_high = 0;
}

