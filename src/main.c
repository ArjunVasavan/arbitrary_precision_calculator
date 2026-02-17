#include "../include/apc.h"

sign result_sign_flag;

int main(int argc, char** argv) {

    if ( argc != 4 ) {
        printf("\033[31m ✗ Error: Operation failed!\033[0m\n");
        printf("\033[36m   Usecase : ./a.out <operand_1> <operator> <operand_2> \033[0m\n");
        printf("\033[36m   Note    : for multiplication use 'x' \033[0m\n");
        exit(EXIT_FAILURE);
    }

    check_if_its_integer(argv[1],argv[3]);

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
    create_list(num2,&head_2,&tail_2);

    starting_zero_remove(&head_1,&tail_1);
    starting_zero_remove(&head_2,&tail_2);

    operation op = which_operation(argv[1],argv[2][0],argv[3],&result_sign_flag,head_1,head_2);

    switch (operator) {
        case '+':{
            if ( op == ADDITION ) {
                addition(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            } else {
                subtraction(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            }
            output_print(head_R,tail_R);
            break;
        }
        case '-':{
            if ( op == ADDITION ) {
                addition(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            } else {
                subtraction(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            }
            output_print(head_R,tail_R);
            break;
        }
        case 'x':{
            multiplication(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            output_print(head_R,tail_R);
            break;
        }
        case '/':{
            division(head_1,tail_1,head_2,tail_2,&head_R,&tail_R);
            output_print(head_R,tail_R);
            break;
        }
        default:{
            printf("\033[31m ✗ Error: Operation failed!\033[0m\n");
            printf("\033[36m   Usecase : ./a.out <operand_1> <operator> <operand_2> \033[0m\n");
            printf("\033[36m   Note    : for multiplication use 'x' \033[0m\n");
            exit(EXIT_FAILURE);
        }
    }

}
