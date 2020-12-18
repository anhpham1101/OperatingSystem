#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 5

struct thread_data {
    int thread_id;
    int sum;
    char* message;
};

struct thread_data thread_data_array[5];

/*void* printHello(void* thread_ID) {
    struct thread_data *my_data;
    long tid;
    tid = (long)thread_ID;
    printf("Hello world! It's me thread #%ld!\n", tid);
    pthread_exit(NULL);
}*/

void* printHello(void *thread_arg) {
    struct thread_data* my_data;

    my_data = (struct thread_data*) thread_arg;
    int taskID = my_data->thread_id;
    int sum = my_data->sum;
    char* hello_msg = my_data->message;
    printf("%s, it's me thread %d, sum = %d\n", hello_msg, taskID, sum);
}

int main(int argc, char** argv) {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t, sum = 0;
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_t tid;
        thread_data_array[t].thread_id = t;
        thread_data_array[t].sum = sum;
        thread_data_array[t].message = "Hello!";
        sum += t;
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, printHello, (void*)&thread_data_array[t]);
        if(rc) {
            printf("ERROR: return from pthread_create() is %d", rc);
            exit(-1);
        }
        //pthread_join(tid, NULL);
    }
    pthread_exit(NULL);
}