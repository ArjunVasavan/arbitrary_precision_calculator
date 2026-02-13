#include "../include/apc.h"

int ascii_to_int(char character ) {
    return character - 48; // 48 => '0'
}

/* NOTE: why **head **tail inspite of *head and *tail
 * if an function must change an pointer use pointer to pointer
 */
status create_list(char* argv, Dlist** head, Dlist** tail) {

    int i = 0;
    Dlist* temp = NULL;

    while (argv[i]) {

        Dlist* new_node = malloc(sizeof(Dlist));
        if ( new_node == NULL )
            return FAILURE; 

        new_node->data = ascii_to_int(argv[i]);
        new_node->next = NULL;

        if ( *head == NULL ) {
            new_node->prev = NULL;
            *head = new_node;
            *tail = new_node;
            temp = new_node;
        } else {
            temp->next = new_node;
            new_node->prev = temp;
            *tail = new_node;
            temp = new_node;
        }
        i+=1;
    }
    return SUCCESS;
}


compare compare_bigint(Dlist* head_1, Dlist* head_2 ) {
    Dlist* temp_1 = head_1;
    Dlist* temp_2 = head_2;

    while (temp_1 && temp_2) {
        temp_1 = temp_1->next;
        temp_2 = temp_2->next;
    }
    if ( temp_1 == NULL && temp_2 == NULL ) {

        temp_1 = head_1;
        temp_2 = head_2;

        while (temp_1 && temp_2) { // as both are same size

            if ( temp_1->data > temp_2->data ) 
                return FIRST_GREATER_THAN_SECOND;
            if (temp_2->data > temp_1->data )
                return SECOND_GREATER_THAN_FIRST;

            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
        }

        return EQUAL;
    } else if ( temp_1 != NULL && temp_2 == NULL ) {
        return FIRST_GREATER_THAN_SECOND;
    } else if ( temp_1 == NULL && temp_2 != NULL) {
        return SECOND_GREATER_THAN_FIRST;
    }
    return EQUAL;
}


