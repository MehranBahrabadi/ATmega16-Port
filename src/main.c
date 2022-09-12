#include "Port.h"


int main(){
    Port portA = {'A'};
    Port portC = {'c'};
    configPort(portA , 'i');
    pullUpPort(portA);

    configPort(portC , 'o');

    return 0;
}