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
    for (int i = 0; i < row * col; i++){
        string_array[i] = to_stringf(float_array[i]);
        //printf("%s\n", string_array[i]);
    } 


    //Count the size of each string in the char* array
    int column_length = 0;
    int total_size_of_floats = 0;
    for(int i = 0; i < row * col; i++){
        char* temp = string_array[i];
        int j = 0;
        while(temp[j] != '\0'){
            total_size_of_floats++;
            //printf("Currently output_float: %d.\n", total_size_of_floats);
            j++;
        }
        /*
            Only when we would go to a new row should we test the size of a row.
            This is the i % row expression.
        */
       int n = i + 1;
        if (n % col == 0){
            if (column_length < total_size_of_floats){
                column_length = total_size_of_floats;
                total_size_of_floats = 0;
            }
        }
    }
    /*
        Total column_length is row_width + border_char. The number of spaces will always equal row_width - 1. This is because only the values in the n x m matrix that
        have a value preceeding and succeeding them, can have a space char ' ' in-between these values. The first and last value of each row are excluded, making them the 
        only values that will not have a space before/after for there corresponding locations. 
    */
    int number_of_spaces = col - 1;
    column_length += number_of_spaces + 2;
    printf("Column length: %d\n", column_length);
    printf("Number of spaces: %d\n", number_of_spaces);

    /*
        When placing chars into the string, we need to know when we are on
        the edges of the array.
        Edge definition: 
            - Let i be index. Then n = i + 1. Then edge = n % column. If edge == 0 or edge == 1 then we are on edge. 
        A top/bottom edge should be:
            - edge = i / row_width. If edge == 0 || edge == number_of_rows, then we are on edge.

        If we are on an edge place the appropriate border char.
    */

    //Make sure there is a counter for current string to input into border.
    int current_string = 0;
    int dimenson_of_border = column_length * char_row;
    for (int i = 0; i < dimenson_of_border; i++){
        int n = i + 1;
        int edge = n % column_length;
        int bottom_edge = char_row - 1;
        int pipe = n / column_length;
        if (edge == 0 || edge == 1){
            border[i] ='|';
         }else if(pipe == 0 || pipe == bottom_edge){
            border[i] = '-';
         }else{
            border[i] = '#';
         }
    }

   /*
    Go back through char array and input strings.
   */
    int beginning_row = column_length;
    int string_index = 0;
    int column_entries = col;
    for (int i = beginning_row; i < (column_length * (char_row - 1)); i++){
        int n = i + 1;
        int edge = n % column_length;
        if (column_entries == 0){
            while(border[i] == '#'){
                //printf("%c", border[i]);
                i++;
            }
            //printf("\n");
            column_entries = col;
        }else if(edge != 1 && edge != 0 && string_index < row * col){
            char* temp_string = string_array[string_index];
            int string_size = size_of_string(temp_string);
            int j;
            for (j = 0; j < string_size; j++){
                border[i + j] = temp_string[j];
            }
            column_entries--;
            i += j;
            string_index++;
        }
    }

    for (int i = 0; i < column_length * char_row; i++){
        if (border[i] == '#') border[i] = ' ';
    }

    for(int i = 0; i < column_length * char_row; i++){
        printf("%c", border[i]);
        if ((i + 1) % (column_length) == 0) print_newline();
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

