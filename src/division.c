#include "../include/apc.h"

// divison using contionous substraction
status division(Dlist* head_1, Dlist* tail_1,
                Dlist* head_2, Dlist* tail_2,
                Dlist** head_R, Dlist** tail_R) {

    if ( head_2->data == 0 && head_2->next == NULL ) {
        printf("Error division by zero!\n");
        return FAILURE;
    }

    compare cmp = compare_bigint(head_1,head_2);
    Dlist*temp_HR;
    Dlist* temp_TR;
    Dlist* big_head;
    Dlist* big_tail;
    Dlist* small_head;
    Dlist* small_tail;
    int div_count = 0;

    if ( cmp == FIRST_GREATER_THAN_SECOND ) {
        big_head = head_1;
        big_tail = tail_1;
        small_head = head_2;
        small_tail = tail_2;
    } else if ( cmp == SECOND_GREATER_THAN_FIRST ) {
        // in this case dividend is smaller than divisor, result is zero
        insert_at_first(0,head_R,tail_R);
        return SUCCESS;
    } else if (cmp == EQUAL) {
        insert_at_first(1,head_R,tail_R);
        return SUCCESS;
    }

    while (compare_bigint(big_head,small_head) != SECOND_GREATER_THAN_FIRST ) {
        subtraction(big_head,big_tail,small_head,small_tail,&temp_HR,&temp_TR);
        big_head = temp_HR;
        big_tail = temp_TR;
        div_count+=1;

        // for checking if result became zero
        if ( big_head->data == 0 && big_head->next == NULL ) {
            break;
        }
    }

    while (div_count != 0) {
        int rem = div_count % 10;
        insert_at_first(rem,head_R,tail_R);
        div_count /= 10;
    }

    starting_zero_remove(head_R,tail_R);
    return SUCCESS;
}
