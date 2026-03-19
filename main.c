#include "header_files/console_control.h"
#include "header_files/game_utility.h"
#include "header_files/game_math.h"
#include "header_files/game_math_utility.h"
#include <stdio.h>
/*
https://github.com/MosesJames46/Baisc_Game
First time using make:
    -gnu.org/software/make/manual/make.html#Reading
*/

int main(void){
    //struct console_struct console;
    //console.width = 36;
    //console.height = 36;
    //allocate_2Darray(console.width, console.height, &console.screen);
    //init_screen(console.width, console.height, &console.screen);
    //print_to_screen(console.width, console.height, &console.screen);
    
    Matrix2x2 A;
    Matrix2x2 B;
    Matrix2x2 C;

    init_mat(&A.m, 2, 2);
    input_array(&A.m, 2, 2);
    print_2Darray(2, 2, &A.m);
    destroy_mat(A.m, 2, 2);

    //init_mat(&B.m, 2, 2);
    //input_array(&B.m, 2, 2);

    //init_mat(&C.m, 2, 2);
    //C = Mat2x2_mul(A, B);
    //output_array(&C.m, 2, 2);
    //destroy_mat(A.m, 2, 2);
    //destroy_mat(B.m, 2, 2);
    
    //char* string = to_stringf(-.2);
    //printf("%s\n", string);
    

    return 0;
}