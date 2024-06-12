#ifndef WELCOME_H
#define WELCOME_H

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "clear_screen.h"

int welcome() {
    printf("Welcome to Snake!!\n"); usleep(1000000);
    printf("Use WASD keys to move the snake.\n"); usleep(1000000);
    printf("Eat the fruit to grow.\n"); usleep(1000000);;
    printf("Press n for normal mode and b for box mode.\n"); usleep(1000000);
    char input; 
    scanf("%c", &input);
    clear_screen();
    if (input == 'n') return 1;
    else if (input == 'b') return 0;
    else {
        printf("Invalid input. Normal mode selected by default.\n");
        usleep(1000000);
        return 1;
    }
}

#endif
