#include "../include/apc.h"

 /* NOTE: single* is used because im not modifying these pointers
 */
status addition(Dlist* head_1, Dlist* tail_1,
                Dlist* head_2, Dlist* tail_2,
                Dlist** head_R, Dlist** tail_R) {

    Dlist* temp_1 = tail_1;
    Dlist* temp_2 = tail_2;

    *head_R = NULL;
    *tail_R = NULL;

    int carry = 0;
    int sum_data;

    while (temp_1 || temp_2) { //means any one temp != NULL 

        int d1 = temp_1 ? temp_1->data : 0;
        int d2 = temp_2 ? temp_2->data : 0;

        int sum_data = d1 + d2 + carry;

        carry = sum_data / 10;
        sum_data %= 10;

        insert_at_first(sum_data,head_R,tail_R);

        if ( temp_1 ) temp_1 = temp_1->prev;
        if ( temp_2 ) temp_2 = temp_2->prev;

    }

    if ( carry ) {
        insert_at_first(carry,head_R,tail_R);
    }
    return SUCCESS;
}
