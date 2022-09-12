
#include "Port.h"



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

void configPin(Pin pin , char state){
    char pinState = toupper(state);
    if(pinState == 'O' || pinState == 'I') {
        switch (pin.port.name) {
            case 'A':
            case 'a':
                (pinState == 'O') ? (DDRA |= (1 << pin.num ) ) : (DDRA &= ~(1 << pin.num ));
                break;
            case 'B':
            case 'b':
                (pinState == 'O') ? (DDRB |= (1 << pin.num ) ) : (DDRB &= ~(1 << pin.num ));
                break;
            case 'C':
            case 'c':
                (pinState == 'O') ? (DDRC |= (1 << pin.num ) ) : (DDRC &= ~(1 << pin.num ));
                break;
            case 'D':
            case 'd':
                (pinState == 'O') ? (DDRD |= (1 << pin.num ) ) : (DDRD &= ~(1 << pin.num ));
                break;
            default:
                return;
        }
    } else{
        return;
    }
}
void setPin(Pin pin){
    switch (pin.port.name) {
        case 'A':
        case 'a':
            PORTA |= (1 << pin.num);
            break;
        case 'B':
        case 'b':
            PORTB |= (1 << pin.num);
            break;
        case 'C':
        case 'c':
            PORTC |= (1 << pin.num);
            break;
        case 'D':
        case 'd':
            PORTD |= (1 << pin.num);
            break;
        default:
            return;
    }
}
void clearPin(Pin pin){
    switch (pin.port.name) {
        case 'A':
        case 'a':
            PORTA &= ~(1 << pin.num);
            break;
        case 'B':
        case 'b':
            PORTB &= ~(1 << pin.num);
            break;
        case 'C':
        case 'c':
            PORTC &= ~(1 << pin.num);
            break;
        case 'D':
        case 'd':
            PORTD &= ~(1 << pin.num);
            break;
        default:
            return;
    }
}
void pullUpPin(Pin pin){
    setPin(pin);
}
int8_t readPin(Pin pin , int precision){
    switch (pin.port.name) {
        case 'A':
        case 'a':
           while(!(PINA & (1 << pin.num))){
               _delay_ms(precision);
               break;
           };
           return !(PINA & (1 << pin.num));
        case 'B':
        case 'b':
            while(!(PINB & (1 << pin.num))){
                _delay_ms(precision);
                break;
            };
            return !(PINB & (1 << pin.num));
        case 'C':
        case 'c':
            while(!(PINC & (1 << pin.num))){
                _delay_ms(precision);
                break;
            };
            return !(PINC & (1 << pin.num));
        case 'D':
        case 'd':
            while(!(PIND & (1 << pin.num))){
                _delay_ms(precision);
                break;
            };
            return !(PIND & (1 << pin.num));
        default:
            return -1;
    }
}
void blinkPin(Pin pin , int duration){
    setPin(pin);
    _delay_ms(duration);
    clearPin(pin);
    _delay_ms(duration);
}