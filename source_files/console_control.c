#include "../header_files/console_control.h"
#include "../header_files/game_utility.h"
#include "../header_files/string_functionality.h"
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
    //Have  char array that holds every char. 
    /*
        We will only access part of the array based on the size of incoming float strings
        from our string_functionalit function.
    */
    char border[1024];

    //Get all floats in matrix
    float float_array[row * col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            float_array[(i * col) + j] = (*screen)[i][j];
        }
    }

    //Convert each value in the array to a string. Might be able to place this inside
    //the for loop above
    char* string_array[row * col];
    for (int i = 0; i < row * col; i++) string_array[i] = to_stringf(float_array[i]);


    //Count the size of each string in the char* array
    int largest_row = 0;
    int total_size_of_floats = 0;
    for(int i = 0; i < row * col; i++){
        char* temp = string_array[i];
        int j = 0;
        while(temp[j] != '\n'){
            total_size_of_floats++;
            printf("Currently output_float: %d.\n", total_size_of_floats);
        }
        //Obtain the largest row by testing against current size of row.
        if (i % row == 0){
            if (largest_row < total_size_of_floats){
                largest_row = total_size_of_floats;
                total_size_of_floats = 0;
            }
        }
    }
    //We can increase the largest row by 2 because we need to account for the borders.
    largest_row += 2;

    /*
        When placing chars into the string, we need to know when we are on
        the edges of the array and when we come across any padding.
        If we are on an edge place a border, if we are on a padding, place
        a border, else place a pound.
    */

    //Make sure there is a counter for current string to input into border.
    int current_string = 0;
    for (int i = 0 ; i < largest_row; i++, current_string++){
         if (i / (largest_row - 1) == 0 || i / (largest_row - 1) == 1){
            border[i] ='-';
         }else if(i % (largest_row - 1) == 0){
            border[i] = '|';
         }else{
            char* string = string_array[current_string];
            int index = 0;
            //Place the string into the array.
            while(string[index] != '\n'){
                border[i] = string[index];
                i++;
                index++;
            }
         }
    }


    /*
        Based on padding size, fill in the input values for the array. 
    */
    
    for(int i = 0; i < largest_row; i++){
        printf("%c", border[i]);
        if (i != 0 && i % (largest_row - 1) == 0) print_newline();
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

