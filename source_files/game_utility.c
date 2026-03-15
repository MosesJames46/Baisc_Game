#include "../header_files/game_utility.h"
#include <stdlib.h>
#include <stdio.h>

/*

3/13/2027: 
    -Jay Kamat input on malloc() and free() and segfaults:
        -Essentially, when calling malloc, os provides memory mostly more than you requested (often)
        for metadata. When you free this memeory it is BAD to access it again because this area
        is now implied to be used for OS. This behaviour is undefined but in some 
        cases you can reaccess that area of memory. It's why accessing it again in test code
        worked. DONT DO THIS, you could be overwriting important information in a real c program.
        Typically, without an OS, you aren't prohibited from writing to this region. This is due
        to nothing preventing you from actually writing to this area given by the OS.
        Get Valgrind to see more info on this.
    -If calling malloc from function either return the pointer output from malloc or
     ensure we are using a poniter to the address of our input pointer. This allows us to
     find the original pointer and assign to it's location the new allocated value.
*/

//It should be noted that all values should be converted to void* when being passed.

/*
    The input to this function should take the address of a double pointer and create
    memory on the heap for a 2D array.
*/
void allocate_2Darray(float*** pointer_to_array, int width, int height){
    //A pointer to a pointer must be used since this point is storing other pointers.
    *pointer_to_array = malloc(sizeof(float*) * width);

    //Using this entry point, each index will hold n values of size int
    for (int i = 0; i < width; i++){
       (*pointer_to_array)[i] = malloc(sizeof(float) * height);
    }
}

/*
Since we allocated individuall, we must free individually as well.
*/
int deallocate_2Darray(float** pointer_to_array, int width, int height){
    for(int i = 0; i < width; i++){
        free(pointer_to_array[i]);
        pointer_to_array[i] = NULL;
    }
    free(pointer_to_array);
    pointer_to_array = NULL;
}

/*
    The pointer being passed is the address of the pointer that holds the array.
    This is important because we wouldnt be able to redirect the pointer otherwise.
*/
void allocate_1Darray(float** pointer_to_array, int size){
    *pointer_to_array = malloc(sizeof(float) * size);
}

void deallocate_1Darray(float* pointer_to_array){
    free(pointer_to_array);
}

void input_array(float*** array, int width, int height){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            printf("Insert value into [%d, %d]. ", i, j);
            scanf("%f", &(*array)[i][j]);
        }
    }
}

/*
    Because array subscription has higher precedence, enclose the pointer in () to perform indirection: printf("%f ", (*array)[i][j]);
*/
void output_array(float*** array, int width, int height){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            printf("%f ", (*array)[i][j]);
        }
        printf("\n");
    }
}