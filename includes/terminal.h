#ifndef TERMINAL_H
#define TERMINAL_H

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

struct termios old_props;

void reset_terminal_attributes() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &old_props);
    exit(0);
}

void set_terminal_attributes() {
    tcgetattr(STDIN_FILENO, &old_props);
    struct termios new_props = old_props;
    new_props.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_props);
    atexit(reset_terminal_attributes);
}


#endif