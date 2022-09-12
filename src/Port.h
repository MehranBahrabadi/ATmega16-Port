//
// Created by Administrator on 9/12/2022.
//

#ifndef ATMEGA16_PORT_PORT_H
#define ATMEGA16_PORT_PORT_H

#ifndef _AVR_IO_H_
#include <avr/io.h>
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


#endif //ATMEGA16_PORT_PORT_H
