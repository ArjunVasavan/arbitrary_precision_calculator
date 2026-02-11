#include "../include/apc.h"
#include <stdio.h>

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

void output_print(Dlist* head, Dlist* tail) {
    printf("\n");
    extern compare result_sign_flag;
    if ( result_sign_flag == NEGATIVE ) {
        printf("-");
    }
    Dlist* temp = head;
    while (temp) {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

status insert_at_last(int data, Dlist **head, Dlist **tail) {

    Dlist* new_node = malloc(sizeof(Dlist));

    if ( new_node == NULL ) {
        return FAILURE;
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;


    if ( *head == NULL && *tail == NULL ) {
        *head = new_node;
        *tail = new_node;
        return SUCCESS;
    }

    new_node->prev = *tail;
    new_node->prev->next = new_node;
    *tail = new_node;
    return SUCCESS;
}

status starting_zero_remove(Dlist** head, Dlist** tail) {

    if (*head == NULL) return FAILURE;

    while ((*head)->data == 0 && ((*head)->next != NULL)) {
        Dlist* temp = *head;
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
    }

    // if only one node is remaining update tail
    if ( (*head)->next == NULL ) {
        *tail = *head;
    }

    return SUCCESS;
}
