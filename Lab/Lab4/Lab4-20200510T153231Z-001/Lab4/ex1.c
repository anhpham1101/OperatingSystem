#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "unistd.h"
#include "string.h"
#include "ex1.h"

void* aligned_malloc(unsigned int size, unsigned int align) {
    if(align <= 0 || size <= 0) return NULL;    // Check the size and align must larger than 0
    unsigned int temp = align;
    while(temp != 2) {  // Check the align must be the power of 2
        if(temp %2 == 1) return NULL;
        else temp /= 2;
    }
    void *p1, *p2;
    p1 = (void*)malloc(size + align - 1 + sizeof(void*));
    if (p1 == NULL) return NULL;   // Check if the allocation is unsuccessful
    else {  // Allocation is successful
        size_t p1_address = (size_t)p1; // Get the address memory allocated in p1
        size_t p1_address_next = (size_t)p1_address + align + sizeof(size_t);    // Find next aligned memory address multiples of alignment
        size_t shift = p1_address_next - (p1_address_next % align);         // Shift and go to memory address satisfy  
        p1 = realloc(p1, shift + size);     // Reallocate new memory block base on old block
        p2 = (void*)(shift);    // Storing aligned memory address
        return p2;  // Return address
    }
}

void* aligned_free(void* ptr) {
    free((void *)(*((size_t *)ptr - 1)));
}