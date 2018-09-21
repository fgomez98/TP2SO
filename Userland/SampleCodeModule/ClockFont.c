#include "ClockFont.h"

unsigned char digitalClockNumbers[] = {
    //8*8 de ancho = 64
    //9*4 de alto = 36
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//1
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//2
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//3
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//4
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//5
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//6
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//7
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//8
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//9
    
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//1
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//2
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//3
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//4
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//5
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//6
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//7
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//8
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//9
    
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//1
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//2
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//3
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    X,X,X,X,X,X,X,X,//4
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//5
    X,X,X,X,X,X,X,X,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,//6
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,//7
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//8
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//9
    
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//1
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//2
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//3
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    X,X,X,X,X,X,X,X,//4
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//5
    X,X,X,X,X,X,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//6
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//7
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//8
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//9
    
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//1
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//2
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//3
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//4
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//5
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//6
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//7
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//8
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//9
    
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//1
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,//2
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,//3
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,//4
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//5
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//6
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//7
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//8
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//9
    
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//1
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,//2
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,//3
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,
    X,X,_,_,_,_,_,_,//4
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//5
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//6
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//7
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//8
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//9
    
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//1
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//2
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//3
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//4
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//5
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//6
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//7
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//8
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//9
   
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//1
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//2
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//3
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//4
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//5
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//6
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//7
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//9
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//9

    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//1
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//2
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//3
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,
    X,X,_,_,_,_,X,X,//4
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,//5
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//6
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//7
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//8
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,
    _,_,_,_,_,_,X,X,//9
};

unsigned char colon[]  = {
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,//1
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//2
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//3
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,//4
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,//5
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//6
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,//7
    _,_,_,X,X,_,_,_,
    _,_,_,X,X,_,_,_,
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,//8
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,//9
};


unsigned char * clock_map(int number) {
    return digitalClockNumbers + BIG_NUMBER_HEIGHT * 8 * number;
}

unsigned char * colon_map() {
    return colon;
}