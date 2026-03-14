#include "header_files/console_control.h"
#include "header_files/game_utility.h"
#include "header_files/game_math.h"
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

    Point p = {50.00, -20.0, 10.0};
    Point v = {206.54, 499.232, -2392.2};

    Point k = point_addition(p, v);
    print_point(k);
    print_newline();

    k = point_subtracition(k, p);
    print_point(k);
    print_newline();

    k = negate_point(k);
    print_point(k);
    print_newline();

    k = mid_point(k, p);
    print_point(p);
    print_newline();
    print_point(k);
    print_newline();

    return 0;
}