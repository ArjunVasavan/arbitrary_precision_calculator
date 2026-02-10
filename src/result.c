#include "../include/apc.h"

status insert_at_first( int data, Dlist** head, Dlist** tail) {

    Dlist* new_node = malloc(sizeof(Dlist));

    if ( new_node == NULL ) {
        return FAILURE;
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    
    if ( *head == NULL && *tail == NULL ) {
        *head = new_node;
        *tail = new_node;
        return SUCCESS;
    }

    new_node->next = *head;
    new_node->next->prev = new_node;
    *head = new_node;
    return SUCCESS;

}
