#include "../include/apc.h"

int main(int argc, char** argv) {
    // argument should be ./a.out 100 + 200
    printf("Argument read is %s %s %s\n",argv[1],argv[2],argv[3]);

    // TODO: validation of input argument

    Dlist* head_1 = NULL;
    Dlist* tail_1 = NULL;
    Dlist* head_2 = NULL;
    Dlist* tail_2 = NULL;
    Dlist* head_R = NULL;
    Dlist* tail_R = NULL;

    char operator = argv[2][0];

    create_list(argv[1],&head_1,&tail_1);
    print_list(head_1,tail_1);
    create_list(argv[3],&head_2,&tail_2);
    print_list(head_2,tail_2);

    switch (operator) {
        case '+':{
            addition(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            printf("Result: \n");
            print_list(head_R,tail_R);
            output_print(head_R,tail_R);
            break;
        }
        case '-':{
            
            subtraction(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            printf("Result: \n");
            print_list(head_R,tail_R);
            output_print(head_R,tail_R);
            break;
        }
        case 'x':{
            multiplication(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            printf("Result: \n");
            print_list(head_R,tail_R);
            output_print(head_R,tail_R);
            break;
        }
        case '/':{
            division(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            printf("Result: \n");
            print_list(head_R,tail_R);
            output_print(head_R,tail_R);
            break;
        }
        default:{
            printf("Error Enter valid operation\n");
            exit(EXIT_FAILURE);
        }
    }

}
