#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "unistd.h"

int main() {
    pid_t pid;
    printf("Process A pid = %d\n", getpid());
    pid = fork();       // A -> B
    if(pid == 0) {      // in process B
        printf("Process B pid = %d is the child of process A pid = %d\n", getpid(), getppid());
        pid = fork();    // B -> E
        if(pid == 0) {  // in process E
            printf("Process E pid = %d is the child of process B pid = %d\n", getpid(), getppid());
            pid = fork();   // E -> I
            if(pid == 0) {  // in process I
                printf("Process I pid = %d is the child of process E pid = %d\n", getpid(), getppid());
            } else if(pid > 0) {  // in process E
                wait(NULL); // wait till process I terminated
            }
        } else if(pid > 0) {    // in process B
            wait(NULL);     // wait till process E terminated
            pid = fork();   // B -> F
            if(pid == 0) {
                printf("Process F pid = %d is the child of process B pid = %d\n", getpid(), getppid());
            } else if(pid > 0){   // in process B
                wait(NULL); // wait till process F terminated
            }
        }
    } else if(pid > 0) {    // in process A
        wait(NULL);     // wait till process B terminated
        pid = fork();   // A -> C
        if(pid == 0) {  // in process C
            printf("Process C pid = %d is the child of process A pid = %d\n", getpid(), getppid());
            pid= fork();    // C -> G;
            if(pid == 0) {  // in process G
                printf("Process G pid = %d is the child of process C pid = %d\n", getpid(), getppid());
            } else if(pid > 0) {  // in process C
                wait(NULL); // wait till process G terminated
            }
        } else if(pid > 0) {    // in process A
            wait(NULL);     // wait till process C terminated
            pid = fork();   //  A -> D
            if(pid == 0) {  // in process D
                printf("Process D pid = %d is the child of process A pid = %d\n", getpid(), getppid());
            } else if(pid > 0) {  // in process A
                wait(NULL);
            }
        }
    }
    return 0;
}