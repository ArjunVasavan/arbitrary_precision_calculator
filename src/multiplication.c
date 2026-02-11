#include "../include/apc.h"

status multiplication(Dlist* head_1, Dlist* tail_1,
                      Dlist* head_2, Dlist* tail_2,
                      Dlist** head_R, Dlist** tail_R) {

    Dlist* multiplier = tail_2;
    Dlist* multiplicand = tail_1;

    int carry = 0;
    int shift_count = 0;

    *head_R = NULL;
    *tail_R = NULL;

    while (multiplier) {

        Dlist* partial_head = NULL;
        Dlist* partial_tail = NULL;

        while (multiplicand) {
            int product = (multiplier->data * multiplicand->data) + carry;
            int result_digit = product % 10;
            carry = product / 10;
            insert_at_first(result_digit,&partial_head,&partial_tail);
            multiplicand = multiplicand->prev;
        }

        if ( carry > 0 ) {
            insert_at_first(carry,&partial_head,&partial_tail);
        }

        for ( int i = 0 ; i < shift_count ; i++ ) {
            insert_at_last(0,&partial_head,&partial_tail);
        }

        // accumulation of additions

        Dlist* acc_head = NULL;
        Dlist* acc_tail = NULL;

        addition(*head_R,*tail_R,partial_head,partial_tail,&acc_head,&acc_tail);

        *head_R = acc_head;
        *tail_R = acc_tail;

        multiplicand = tail_1;
        carry = 0;
        multiplier = multiplier->prev;
        shift_count+=1;
    }


    return SUCCESS;
}

