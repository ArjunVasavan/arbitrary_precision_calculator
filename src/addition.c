#include "../include/apc.h"
#include <time.h>

status addition(Dlist** head_1, Dlist** tail_1,
                Dlist** head_2, Dlist** tail_2,
                Dlist** head_R, Dlist** tail_R) {
    Dlist* temp_1 = *tail_1;
    Dlist* temp_2 = *tail_2;

    int carry = 0;
    int sum_data;

    while (temp_1 || temp_2) { //means any one temp != NULL 

        if ( temp_1 && temp_2 ) { // means both value havent ended
            if ( (sum_data = temp_1->data + temp_2->data + carry ) > 9 ) {
                carry = 1;
            } else {
                carry = 0;
            }
        } else if (temp_1 == NULL && temp_2 != NULL) {
        
            if ( (sum_data = temp_2->data + carry ) > 9 ) {
                carry = 1;
            } else {
                carry = 0;
            }
        } else if (temp_1 != NULL && temp_2 == NULL) {
            if ( (sum_data = temp_1->data + carry) > 9 ){
                carry = 1;
            } else {
                carry = 0;
            }
        }
        sum_data%=10;
        insert_at_first(sum_data,head_R,tail_R);

        if ( temp_1 ) {
            temp_1 = temp_1->prev;
        }

        if ( temp_2 ) {
            temp_2 = temp_2->prev;
        }

    }

    if ( carry == 1 ) {
        insert_at_first(1,head_R,tail_R);
    }
    return SUCCESS;
}
