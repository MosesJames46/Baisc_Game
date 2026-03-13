#include "header_files/console_control.h"
#include "header_files/game_utility.h"
#include <stdio.h>

int main(void){
    struct console_struct console;
    console.array = NULL;
    console.width = 256;
    console.height = 256;
    if(!console.array){
        printf("Array is NULL.\n");
    }
    //console.array = malloc(sizeof(int) * console.width * console.height);
   console.array = allocate_2Darray(console.width, console.height, console.array);
    if(console.array){
        printf("Array is not NULL.\n");
    }
    //printf("The status of malloc: %d\n", successful_malloc);
    //int successful_free = deallocate_2Darray(console.array);
    //printf("The status of deallocation: %d", successful_malloc);

    return 0;
}