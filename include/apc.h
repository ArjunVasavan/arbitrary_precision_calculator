#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct Dlist{  // NOTE: in typedef we can put name early also
    int data;
    struct Dlist* prev;
    struct Dlist* next;
}Dlist;

typedef enum {
    SUCCESS, // 0
    FAILURE // 1
}status;


status create_list(char* argv, Dlist** head, Dlist** tail);
void print_list(Dlist* head,Dlist* tail);

#endif
