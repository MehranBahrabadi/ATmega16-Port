//
// Created by Administrator on 9/12/2022.
//

#include "Port.h"
#include <ctype.h>

void configPort(Port port , char state){
    char portState = toupper(state);
    if(portState == 'O' || portState == 'I') {
        switch (port.name) {
            case 'A':
            case 'a':
                (portState == 'O') ? (DDRA = 0xFF) : (DDRA=0x00);
                break;
            case 'B':
            case 'b':
                (portState == 'O') ? (DDRB = 0xFF) : (DDRB=0x00);
                break;
            case 'C':
            case 'c':
                (portState == 'O') ? (DDRC = 0xFF) : (DDRC=0x00);
                break;
            case 'D':
            case 'd':
                (portState == 'O') ? (DDRD = 0xFF) : (DDRD=0x00);
                break;
            default:
                return;
        }
    } else{
        return;
    }
}
void setPort(Port port){
    switch (port.name) {
        case 'A':
        case 'a':
            PORTA = 0xFF;
            break;
        case 'B':
        case 'b':
            PORTB = 0xFF;
            break;
        case 'C':
        case 'c':
            PORTC = 0xFF;
            break;
        case 'D':
        case 'd':
            PORTD = 0xFF;
            break;
        default:
            return;
    }
}
void clearPort(Port port){
    switch (port.name) {
        case 'A':
        case 'a':
            PORTA = 0x00;
            break;
        case 'B':
        case 'b':
            PORTB = 0x00;
            break;
        case 'C':
        case 'c':
            PORTC = 0x00;
            break;
        case 'D':
        case 'd':
            PORTD = 0x00;
            break;
        default:
            return;
    }
}
short readPort(Port port){
    switch (port.name) {
        case 'A':
        case 'a':
            return PINA;
        case 'B':
        case 'b':
            return PINB;
        case 'C':
        case 'c':
            return PINC;
        case 'D':
        case 'd':
            return PIND;
        default:
            return -1;
    }
}
void pullUpPort(Port port){
    setPort(port);
}