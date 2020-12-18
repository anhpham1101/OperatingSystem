#include "stdio.h"
#include "stdlib.h"
#include "ex1.h"

int main(int argc, char ** argv) {
    size_t size = 16;
    size_t align = 128;
    int *p = aligned_malloc(size, align);
    printf("Address of allocated: %p\n", p);
    aligned_free(p);
    printf("Address of allocated: %p\n", p);
    return 0;
}