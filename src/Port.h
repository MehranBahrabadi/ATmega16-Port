//
// Created by Administrator on 9/12/2022.
//

#ifndef ATMEGA16_PORT_PORT_H
#define ATMEGA16_PORT_PORT_H

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef __CTYPE_H_
#include <ctype.h>
#endif


#define F_CPU   1000000UL


#ifndef _UTIL_DELAY_H_
#include "util/delay.h"
#endif


// ----------------  Variables  -----------------
typedef struct {
    char name;
}Port;

typedef struct {
    Port port;
    uint8_t num;
}Pin;

// ----------------  Functions  -----------------
void configPort(Port port , char state);
void setPort(Port port);
void clearPort(Port port);
short readPort(Port port);
void pullUpPort(Port port);


void configPin(Pin pin , char state);
void setPin(Pin pin);
void clearPin(Pin pin);
int8_t readPin(Pin pin , int precision);
void pullUpPin(Pin pin);
void blinkPin(Pin pin ,int duration);

#endif //ATMEGA16_PORT_PORT_H
