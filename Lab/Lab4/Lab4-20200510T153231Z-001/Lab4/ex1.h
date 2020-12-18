#include "stdio.h"
#include "stdlib.h"
#ifndef ALIGNED_MALLOC
#define ALIGNED_MALLOC
void* aligned_malloc(unsigned int size, unsigned int align);
void* aligned_free(void *ptr);
#endif