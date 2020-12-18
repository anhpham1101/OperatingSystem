#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"

int value = 5;

int main(int argc, char** argv) {
    pid_t pid;
    pid = fork();
    if(pid == 0) {
        value += 15;
        printf("Children value  = %d\n", value);
        return 0;
    } else if(pid > 0) {
        printf("Parent value  = %d\n", value);
        return 0;
    }
}