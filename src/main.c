#include "../include/apc.h"
#include <stdio.h>

sign result_sign_flag;

int main(int argc, char** argv) {
    // argument should be ./a.out 100 + 200
    printf("Argument read is %s %s %s\n",argv[1],argv[2],argv[3]);

    Dlist* head_1 = NULL;
    Dlist* tail_1 = NULL;
    Dlist* head_2 = NULL;
    Dlist* tail_2 = NULL;
    Dlist* head_R = NULL;
    Dlist* tail_R = NULL;

    char operator = argv[2][0];


    char *num1 = (argv[1][0] == '-' || argv[1][0] == '+') ? argv[1] + 1 : argv[1];
    char *num2 = (argv[3][0] == '-' || argv[3][0] == '+') ? argv[3] + 1 : argv[3];

    create_list(num1,&head_1,&tail_1);
    print_list(head_1,tail_1);
    create_list(num2,&head_2,&tail_2);
    print_list(head_2,tail_2);

    operation op = which_operation(argv[1],argv[2][0],argv[3],&result_sign_flag,head_1,head_2);

    switch (operator) {
        case '+':{
            if ( op == ADDITION ) {
                printf("Addition\n");
                addition(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            } else {
                printf("subtraction\n");
                subtraction(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            }
            printf("Result: \n");
            print_list(head_R,tail_R);
            output_print(head_R,tail_R);
            break;
        }
        case '-':{
            if ( op == ADDITION ) {
                printf("Addition\n");
                addition(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            } else {
                printf("Subtraction\n");
                subtraction(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            }
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
