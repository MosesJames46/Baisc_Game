#include "../header_files/console_control.h"
#include <stdio.h>

void init_screen(int width, int height, int*** screen){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            (*screen)[i][j] = '#';
        }
    }
}

void print_to_screen(int width, int height, int*** screen){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            printf("%c", (*screen)[i][j]);
        }
        printf("\n");
    }
}