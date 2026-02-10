#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

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
status addition(Dlist** head_1, Dlist** tail_1,
                Dlist** head_2, Dlist** tail_2,
                Dlist** head_R, Dlist** tail_R);
status insert_at_first( int data, Dlist** head, Dlist** tail);

#endif
