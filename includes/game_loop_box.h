#ifndef GAME_LOOP_BOX_H
#define GAME_LOOP_BOX_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include "game_loop_normal.h"

#define HEIGHT 20
#define WIDTH 40


void game_loop_box(int *head_x, int *head_y, int *fruit_x, int *fruit_y, int tail_x[],
               int tail_y[], int *tail_length, int *score) {
    int prev_head_x = *head_x;
    int prev_head_y = *head_y;

    for (int i = *tail_length - 1; i > 0; i--) {
        tail_x[i] = tail_x[i - 1];
        tail_y[i] = tail_y[i - 1];
    }
    tail_x[0] = prev_head_x;
    tail_y[0] = prev_head_y;

    switch (dir) {
        case UP:
            (*head_y)--;
            break;
        case DOWN:
            (*head_y)++;
            break;
        case LEFT:
            (*head_x)--;
            break;
        case RIGHT:
            (*head_x)++;
            break;
        case STOP:
            break;
    }

    if (*head_x < 0 || *head_x >= WIDTH) {
        printf("\tYou lose!\t\n");
        exit(0);
    }
    if (*head_y < 0 || *head_y >= HEIGHT) {
        printf("\tYou lose!\t\n");
        exit(0);
    }

    for (int i = 0; i < *tail_length; i++) {
        if (tail_x[i] == *head_x && tail_y[i] == *head_y) {
            printf("\tYou lose!\t\n");
            exit(0);
        }
    }

    if (*head_x == *fruit_x && *head_y == *fruit_y) {
        (*score) += 10;
        *fruit_x = rand() % WIDTH;
        *fruit_y = rand() % HEIGHT;
        (*tail_length)++;
    }
}
#endif