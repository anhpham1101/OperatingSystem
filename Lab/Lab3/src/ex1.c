#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "unistd.h"

int main() {
    FILE *fs = fopen("numbers.txt", "r");
    pid_t pid;
    int arr[100], count = 0;
    int result = 0;
    if(fs == NULL) perror("Error opening file");
    else {
        while(!feof(fs)) {
            fscanf(fs, "%d", &arr[count++]);
        }
    }
    fclose(fs);
    pid = fork();
    if(pid == 0) {
        for(int i = 0; i < count; i++) {
            if(arr[i] % 3 == 0) result++;
        }
    } else if(pid > 0) {
        wait(NULL);
        for(int i = 0; i < count; i++) {
            if(arr[i] % 2 == 0) result++;
        }
    }
    printf("%d\n", result);
    return 0;
}