#include "../header_files/console_control.h"
#include "../header_files/game_utility.h"
#include <stdio.h>

void init_screen(int row, int col, int*** screen){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            (*screen)[i][j] = '-';
        }
    }
}

void print_to_screen(int row, int col, int*** screen){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%c", (*screen)[i][j]);
        }
        printf("\n");
    }
}



/*
    Should take in a an array of numbers, typically a float and output them to a string with
    a border. 
*/
void print_2Darray(int row, int col, float*** screen){
    char border_char = '-';
    //Add a 2 represents adding the top/bottom row and the first/last edges.
    int char_col = col + 2;
    int char_row = row + 2;
    char border[char_row][char_col];


    /*
        When placing chars into the string, we need to know when we are on
        the edges of the array and when we come across any padding.
        If we are on an edge place a border, if we are on a padding, place
        a border, else place a pound.
    */
    for (int i = 0 ; i < char_row; i++){
        for (int j = 0; j < char_col; j++){
            //col - 1 is the max index of array.
            if (j == 0 || j == (char_row - 1)) {
                border[i][j] = border_char;
            }else if (i == 0 || i == (char_col - 1)){
                border[i][j] = border_char;
            }else{
                border[i][j] = '#';
            }
        }
    }


    /*
        Based on padding size, fill in the input values for the array. 
    */
    
    for(int i = 0; i < char_row; i++){
        for(int j = 0; j < char_col; j++){
            printf("%c", border[i][j]);
            if (j == char_col - 1) print_newline();
        }
    }
    
}

void print_newline(){
    printf("\n");
}


void input_2Darray(float*** pointer_to_array, int row, int column){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            printf("Please enter the value for row %d column %d. ", i, j);
            scanf("%f", &(*pointer_to_array)[i][j]);
        }
    }
}

