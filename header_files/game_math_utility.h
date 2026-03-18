#include "string_functionality.h"

#ifndef GAME_MATH_UTILITY
#define GAME_MATH_UTILITY

/*
This header file is responisible for controling the output of a matrix.

Use scanf to take input. That input gets put into am array since the goal is to obtain inputs in order.
Will need a function to transform input floats into a string.
*/

typedef struct Matrix_Descriptor_Struct Matrix_Descriptor;
struct Matrix_Descriptor_Struct{
    char* layout;
    int padding;
    int row;
    int col;
};

//const char border_char = '-';
//const char space_char = ' ';


void init_mat(float*** mat, int width, int height);
void destroy_mat(float** mat, int width, int height);

void set_layout();

#endif