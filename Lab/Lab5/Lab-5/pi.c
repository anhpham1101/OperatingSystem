#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "pthread.h"
#define NUM_THREADS 10
#define CONST 1000000000

long point_in_circle = 0;

void* calculate(void* param) {
    double x, y;
    long in_circle = 0;
    long upper = (long)param;
    unsigned int rand_number = rand();
    for(int i = 0; i < upper; i++) {
        x = rand_r(&rand_number) / (RAND_MAX + 1.0) * 2 - 1;
		y = rand_r(&rand_number) / (RAND_MAX + 1.0) * 2 - 1;
        if(x*x + y*y <= 1) in_circle++;
    }
    point_in_circle += in_circle;
}

int main(int argc, char *argv[]) {
    struct timespec begin, end;
    double duration;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    // Handle error
    if(argc != 2) {
        fprintf(stderr, "Error: Missing argument integer\n");
        return -1;
    }
    if(atoi(argv[1]) < 0) {
        fprintf (stderr, "Error: Negative number\n") ;
        return -1;
    }
    // Read number of points to estimate PI
    long point_in_square = atoi(argv[1]);
    long upper_number = point_in_square / NUM_THREADS;
    pthread_t thread[NUM_THREADS];
    int i;
    // Create multithread
    for(i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread[i], NULL, (void*)calculate, (void*)upper_number);
        printf("Thread (%u) has created a new thread (%u) ... \n", (int)pthread_self(), (int)thread[i]);
    }
    for(i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread[i], NULL);
    }
    // Calculate result
    double pi = (double)4*point_in_circle/point_in_square;
    printf("Number of in_circle points: %ld\n", point_in_circle);
    printf("Value of PI estimated by %ld intervals is: %lf\n", point_in_square, pi);
    clock_gettime(CLOCK_MONOTONIC, &end);
    // Calculate time
    duration = end.tv_sec - begin.tv_sec;
    duration += (end.tv_nsec - begin.tv_nsec)/(double)CONST;
    printf("Duration: %.6lf\n", duration);
    
    pthread_exit(NULL);
}
