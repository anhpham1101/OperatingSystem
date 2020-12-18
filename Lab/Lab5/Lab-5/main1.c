#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;
void* runner(void* param);

int main(int argc, int* argv[]) {
    pthread_t tid;
    pthread_attr_t attr;

    if(argc != 2) {
        fprintf(stderr, "usage: a.out <integer_value>\n");
        return -1;
    }
    if(atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }
    //get the default attributes
    pthread_attr_init(&attr);
    //create a new thread
    pthread_create(&tid, &attr, runner, argv[1]);
    //wait for the thread to exit
    pthread_join(tid, NULL);
    printf("sum = %d\n", sum);
}

//The thread will begin control in this function

void* runner(void* param) {
    int i, upper = atoi(param);
    sum = 0;
    for(i = 1; i <= upper; i++) sum += i;
    pthread_exit(0);
}