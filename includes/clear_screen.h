#ifndef clear_screen_h
#define clear_screen_h

#include <stdlib.h>

void clear_screen(){
    #ifdef _Win32
        system("cls");
    #else
        system("clear");
    #endif
    
}

#endif