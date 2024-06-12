#include <stdio.h>
#include <time.h>
#include <sys/select.h>
#include "includes/draw.h"
#include "includes/game_loop_normal.h"
#include "includes/game_loop_box.h"
#include "includes/terminal.h"
#include "includes/welcome.h"
/*if you're reading this and wondering what everyone else does - YES I wrote all of the above .h files and NO those weren't just copied and pasted*/



enum Direction dir = STOP;

int score;
int fruit_x, fruit_y;
int head_x, head_y;
int tail_x[100], tail_y[100], tail_length;

void setup() {
    head_x = WIDTH / 2;
    head_y = HEIGHT / 2;
    fruit_x = rand() % WIDTH;
    fruit_y = rand() % HEIGHT;
    score = 0;
    tail_length = 0;
}
int sleep_time(int base_sleep_time, int score){
    int sleep_time = base_sleep_time - score * 1000;
    if (sleep_time < 20000) {
        sleep_time = 20000;
    }
    return sleep_time;

}
int main() {
    srand(time(NULL));
    set_terminal_attributes();
    setup();

    //Game initialises
    if (welcome()){
        //game starts in normal  mode
        while (1) {
            draw(&head_x, &head_y, &fruit_x, &fruit_y, tail_x, tail_y, &tail_length, &score);
            input();
            game_loop(&head_x, &head_y, &fruit_x, &fruit_y, tail_x, tail_y, &tail_length, &score);
            usleep(sleep_time(200000, score));
        }
    }
    else {
        while (1) {
            //game starts in box mode 
            draw(&head_x, &head_y, &fruit_x, &fruit_y, tail_x, tail_y, &tail_length, &score);
            input();
            game_loop_box(&head_x, &head_y, &fruit_x, &fruit_y, tail_x, tail_y, &tail_length, &score);
            usleep(sleep_time(200000, score));
        }
    }        

    exit(0);
}

