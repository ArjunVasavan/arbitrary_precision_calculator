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

operation which_operation(char *operand_1,
                          char operation,
                          char *operand_2,
                          sign *result_sign_flag,
                          Dlist *head_1,
                          Dlist *head_2) {
    sign sign1 = POSITIVE;
    sign sign2 = POSITIVE;

    if (operand_1[0] == '-')
        sign1 = NEGATIVE;

    if (operand_2[0] == '-')
        sign2 = NEGATIVE;

    if (operation == '*' || operation == '/') {
        if (sign1 == sign2)
            *result_sign_flag = POSITIVE; 

        else
            *result_sign_flag = NEGATIVE;

        return REGULAR;
    }

    if (operation == '+') {

        if (sign1 == sign2) {
            *result_sign_flag = sign1;

            return ADDITION;
        }
        else {

            compare cmp = compare_bigint(head_1, head_2);

            if (cmp == FIRST_GREATER_THAN_SECOND)
                *result_sign_flag = sign1;
            else if (cmp == SECOND_GREATER_THAN_FIRST)
                *result_sign_flag = sign2;
            else
                *result_sign_flag = POSITIVE;

            return SUBTRACTION;
        }
    }


    if (operation == '-') {
        if (sign1 != sign2) {
            *result_sign_flag = sign1;
            return ADDITION;
        } else {
            compare cmp = compare_bigint(head_1, head_2);

            if (cmp == FIRST_GREATER_THAN_SECOND)
                *result_sign_flag = sign1;
            else if (cmp == SECOND_GREATER_THAN_FIRST)
                *result_sign_flag = (sign1 == POSITIVE) ? NEGATIVE : POSITIVE;
            else
                *result_sign_flag = POSITIVE;

            return SUBTRACTION;
        }
    }

    return REGULAR;
}

void output_print(Dlist* head, Dlist* tail) {
    printf("\n");
    extern sign result_sign_flag;
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
