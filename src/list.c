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

status check_if_its_integer ( char* str1, char* str2 ) {

    int i = 0;

    while (str1[i]) {
        if ( (str1[i] >= 'a' && str1[i] <= 'z') || (str1[i]>= 'A' && str1[i] <= 'Z') ) {
            printf("\033[31m ✗ Error: Operation failed!\033[0m\n");
            printf("\033[33m ⚠ Warning: Only Integer can be used\033[0m\n");
            exit(EXIT_FAILURE);
        }
        i+=1;
    }
    i = 0;

    while (str2[i]) {
        if ( (str2[i] >= 'a' && str2[i] <= 'z') || (str2[i]>= 'A' && str2[i] <= 'Z') ) {
            printf("\033[31m ✗ Error: Operation failed!\033[0m\n");
            printf("\033[33m ⚠ Warning: Only Integer can be used\033[0m\n");
            exit(EXIT_FAILURE);
        }
        i+=1;
    }

    return SUCCESS;
}
