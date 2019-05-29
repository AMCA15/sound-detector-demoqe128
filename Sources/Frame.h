/*
 * Frame.h
 *
 *  Created on: Feb 18, 2019
 *  Author: Anderson Contreras
 */

#ifndef FRAME_H_
#define FRAME_H_

#include "PE_Types.h"

#define FRAME_SIZE 2
#define ANALOG_OUT Data.Analog.byte
#define SENSOR_1   Data.Digital.sensor1
#define SENSOR_2   Data.Digital.sensor2

extern volatile char is_Data_Ready;
extern volatile char *BufferSerialCount;

// Struct for Digitals & Analog Data
struct DATA {
    union ANALOG
    {
        char signed byte;
        struct HALFBYTE
        {
            char low  : 4;
            char high : 4;
        } halfbyte;
    } Analog;
    struct DIGITAL 
    {
        char sensor1 : 1;
        char sensor2 : 1;
    } Digital;
};
extern struct DATA Data;

// Data frame struct
struct FRAME {
    byte Ana_low  : 4;
    byte          : 3;
    byte Syn_low  : 1;
    byte Ana_high : 4;
    byte Dig_1    : 1;
    byte Dig_2    : 1;
    byte Syn_high : 1;
};
extern struct FRAME Frame;

// Function for packing the data
void Pack(struct FRAME *frame, struct DATA data);

#endif /* FRAME_H_ */
