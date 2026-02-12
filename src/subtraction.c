#include "../include/apc.h"

/* NOTE: single* is used because im not modifying these pointers
 */


status subtraction(Dlist* head_1, Dlist* tail_1,
                   Dlist* head_2, Dlist* tail_2,
                   Dlist** head_R, Dlist** tail_R) {

    extern compare result_sign_flag;

    compare cmp = compare_bigint(head_1,head_2);
    // cmp will compare if equal , greater or lesser
    *head_R = NULL;
    *tail_R = NULL;

    if ( cmp == EQUAL ) {
        insert_at_first(0,head_R,tail_R);
        return SUCCESS;
    }
    // as both are equal anyway the result will be 0

    Dlist* t_big; // tail of big
    Dlist* t_small; // tail of small
    int borrow = 0;
    int digit_big;
    int digit_small;


    if ( cmp == FIRST_GREATER_THAN_SECOND ) {
        // here result is positive
        t_big = tail_1;
        t_small = tail_2;
        result_sign_flag = POSITIVE;

    } else if ( cmp == SECOND_GREATER_THAN_FIRST ) {
        // here result is negative
        t_big = tail_2;
        t_small = tail_1;
        result_sign_flag = NEGATIVE;
    }

    while (t_big) {

        digit_big = t_big->data;
        if ( t_small == NULL ) {
            digit_small = 0;
        } else {
            digit_small = t_small->data;
        }

        int raw = digit_big - borrow - digit_small;
        int result_digit;

        if ( raw >= 0 ) {
            result_digit = raw;
            borrow = 0;
        } else {
            result_digit = raw + 10;
            borrow = 1;
        }

        insert_at_first(result_digit,head_R,tail_R);

        t_big = t_big->prev;
        t_small = t_small ? t_small->prev : NULL;
    }

    starting_zero_remove(head_R,tail_R);

    return SUCCESS;
}

