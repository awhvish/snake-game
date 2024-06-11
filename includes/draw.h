#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>
#include "clear_screen.h"

#define HEIGHT 20
#define WIDTH 40    

void draw(int *head_x_ptr, int *head_y_ptr, int *fruit_x_ptr, int *fruit_y_ptr,
          int tail_x[], int tail_y[], int *tail_length_ptr, int *score_ptr) {
            
    clear_screen();
    printf("\t\x1b[31mWelcome to the Snake Game!\x1b[0m\n");
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("~");
    }

    for (int i = 0; i < HEIGHT; i++) {
        printf("\n|");
        for (int j = 0; j < WIDTH; j++) {
            if (i == *head_y_ptr && j == *head_x_ptr) {
                printf("\x1b[32mO\x1b[0m");
            } else if (i == *fruit_y_ptr && j == *fruit_x_ptr) {
                printf("\x1b[43m \x1b[0m");
            } else {
                int tail_found = 0;
                for (int k = 0; k < *tail_length_ptr; k++) {
                    if (tail_x[k] == j && tail_y[k] == i) {
                        printf("\x1b[32mo\x1b[0m");
                        tail_found = 1;
                        break;
                    }
                }
                if (!tail_found)
                    printf(" ");
            }
        }
        printf("|");
    }

    printf("\n");
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("~");
    }
    printf("\nScore: %d", *score_ptr);
}

#endif
