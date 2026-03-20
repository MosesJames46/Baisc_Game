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

    //init_mat(&A.m, 2, 2);
    //input_array(&A.m, 2, 2);
    //print_2Darray(2, 2, &A.m);
    //destroy_mat(A.m, 2, 2);

    char* float_string = to_stringf(000.001205);
    int size = size_of_string(float_string);
    printf("%s\n", float_string);

    //int mid = midpoint(0, 11);
    //printf("Midpoint value: %d\n", mid);

    return 0;
}