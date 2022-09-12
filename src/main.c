#include "Port.h"
#define true 1

int main(){

    Pin led1 = {{'D'} , 0};
    Pin led2 = {{'D'} , 7};
    Pin key = {{'A'} , 1};
    Pin exit = {{'A'} , 7};

    configPin(led1 , 'O');
    configPin(led2 , 'O');

    configPin(key , 'I');
    configPin(exit , 'I');
    pullUpPin(key);
    pullUpPin(exit);
    int count = 0;

    while(true){
        if(readPin(key , 100)) {
            setPin(led1);
            count++;
            _delay_ms(100);
            clearPin(led1);
        }
        if (count >= 10){
            setPin(led2);
            _delay_ms(100);
            clearPin(led2);
            count = 0;
        }
        if(readPin(exit , 100))
            break;
    }



    return 0;
}