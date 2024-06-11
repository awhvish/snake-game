#ifndef GAME_LOOP_NORMAL_H
#define GAME_LOOP_NORMAL_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

#define HEIGHT 20
#define WIDTH 40

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STOP
};

extern enum Direction dir;

void game_loop(int *head_x, int *head_y, int *fruit_x, int *fruit_y, int tail_x[],
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

    if (*head_x < 0) *head_x = WIDTH - 1;
    else if (*head_x >= WIDTH) *head_x = 0;

    if (*head_y < 0) *head_y = HEIGHT - 1;
    else if (*head_y >= HEIGHT) *head_y = 0;

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

int input_available() {
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
}

void input() {
    if (input_available()) {
        char ch = getchar();
        switch (ch) {
            case 'a':
                dir = LEFT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 'x':
                exit(0);
            default:
                break;
        }
    }
}

#endif