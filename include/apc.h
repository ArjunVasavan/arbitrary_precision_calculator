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
    SUCCESS,
    FAILURE 
}status;

typedef enum {
    FIRST_GREATER_THAN_SECOND,
    SECOND_GREATER_THAN_FIRST,
    EQUAL
}compare;

typedef enum {
    POSITIVE,
    NEGATIVE
}sign;

typedef enum{
    ADDITION,
    SUBTRACTION,
    REGULAR
} operation;

status create_list(char* argv, Dlist** head, Dlist** tail);
void print_list(Dlist* head,Dlist* tail);
status addition(Dlist* head_1, Dlist* tail_1,
                Dlist* head_2, Dlist* tail_2,
                Dlist** head_R, Dlist** tail_R);
status division(Dlist* head_1, Dlist* tail_1,
                Dlist* head_2, Dlist* tail_2,
                Dlist** head_R, Dlist** tail_R);
status subtraction(Dlist* head_1, Dlist* tail_1,
                   Dlist* head_2, Dlist* tail_2,
                   Dlist** head_R, Dlist** tail_R);
status multiplication(Dlist* head_1, Dlist* tail_1,
                      Dlist* head_2, Dlist* tail_2,
                      Dlist** head_R, Dlist** tail_R);
operation which_operation(char *operand_1,
                          char operation,
                          char *operand_2,
                          sign *result_sign_flag,
                          Dlist *head_1,
                          Dlist *head_2);
status insert_at_first( int data, Dlist** head, Dlist** tail);
compare compare_bigint(Dlist* head_1, Dlist* head_2 );
status starting_zero_remove(Dlist** head, Dlist** tail);
status insert_at_last(int data, Dlist **head, Dlist **tail);
void output_print(Dlist* head, Dlist* tail);
status check_if_its_integer ( char* str1, char* str2 );
#endif
