#include "../include/apc.h"

// divison using contionous substraction
status division(Dlist* head_1, Dlist* tail_1,
                Dlist* head_2, Dlist* tail_2,
                Dlist** head_R, Dlist** tail_R) {

    compare cmp = compare_bigint(head_1,head_2);

    Dlist*temp_HR;
    Dlist* temp_TR;

    Dlist* big_head;
    Dlist* big_tail;
    Dlist* small_head;
    Dlist* small_tail;
    int div_count = 1;

    if ( cmp == FIRST_GREATER_THAN_SECOND ) {
        big_head = head_1;
        big_tail = tail_1;
        small_head = head_2;
        small_tail = tail_2;
    } else if ( cmp == SECOND_GREATER_THAN_FIRST ) {
        big_head = head_2;
        big_tail = tail_2;
        small_head = head_1;
        small_tail = tail_1;
    } else if (cmp == EQUAL) {
        insert_at_first(1,head_R,tail_R);
        printf("Now the div_count is %d\n",div_count);
        return SUCCESS;
    }


    while (compare_bigint(big_head,small_head) != SECOND_GREATER_THAN_FIRST &&
        compare_bigint(big_head,small_head) != EQUAL) {
        subtraction(big_head,big_tail,small_head,small_tail,&temp_HR,&temp_TR);
        big_head = temp_HR;
        big_tail = temp_TR;
        div_count+=1;
    }

    printf("Now the div_count is %d\n",div_count);

    while (div_count != 0) {
        int rem = div_count % 10;
        insert_at_first(rem,head_R,tail_R);
        div_count /= 10;
    }

    return SUCCESS;
}
