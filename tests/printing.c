#include "../include/apc.h"
 
// this functions are used for testing the code only

void print_list(Dlist* head,Dlist* tail) {

    if ( head == NULL ) {
        printf("List is empty\n");
        return;
    }

    printf("HEAD <-> ");

    Dlist* temp = head;

    while (temp!= NULL) {

        printf("%d",temp->data);
        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf(" <-> Tail\n");
}
