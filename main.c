#include "header_files/console_control.h"
#include "header_files/game_utility.h"
#include <stdio.h>

int main(void){
    struct console_struct console;
    console.width = 256;
    console.height = 256;
    //allocate_2Darray(console.width, console.height, &console.screen);
    //init_screen(console.width, console.height, console.screen);
    //print_to_screen(console.width, console.height, console.screen);
    //int success = deallocate_2Darray(console.width, console.height, console.screen);

    int* some_array;
    allocate_1Darray(10, &some_array);
    deallocate_1Darray(some_array);
    return 0;
}