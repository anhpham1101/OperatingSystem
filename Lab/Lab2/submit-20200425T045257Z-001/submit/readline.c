#include "readline.h"
#include <stdio.h>
#include <string.h>

int read_line(char* str) {
    int result = 0;
    char c;
    while(c = getchar()) {
        if (c == EOF || c == '\n') break;
        else if (result < 100) {
            *str++ = c;
            result++;
        }
    }
    *str = '\0';
    if(c == EOF) return -1;
    else return result;
}