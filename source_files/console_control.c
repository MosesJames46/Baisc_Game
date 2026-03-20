#include "../header_files/console_control.h"
#include "../header_files/game_utility.h"
#include "../header_files/string_functionality.h"
#include "../header_files/game_math.h"
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


    /*
        Instead obtain largest string. The largest string now is how the rest of our
        matrix string will be spaced.
    */
    int column_length = 0;
    int largest_string = get_largest_stringf(float_array, row * col);
    printf("The largest float string: %d\n", largest_string);
    column_length = largest_string * col;
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
    int edge;
    int n;
    for (int i = 0; i < dimenson_of_border; i++){
        n = i + 1;
        edge = n % column_length;
        int bottom_edge = char_row - 1;
        int border_dash = i / column_length;
        //border_dash == 0 || border_dash == bottom_edge
        if (border_dash == 0 || border_dash == bottom_edge){
            border[i] ='-';
         }else if(edge == 0 || edge == 1){
            border[i] = '|';
         }else{
            border[i] = '#';
         }
    }

   /*
    Go back through char array and input strings.
   */
    /*
        We want to skip the first row and the last row entriely. We can accomplish so by doing the following:
        2nd row = column_width.
        2nd to last row = column_width * (number_of_rows - 1).

        Next, input values from our string array into the border char.
        We want to obtain the current entry point and based on that point, 
        attempt to center within that entry location.

        We can do so by starting in the very center of the entry.
        In the input string, we go to the beginning of the array starting at it's
        midpoint. We know since the entry points are all atleast the size of the 
        largest string, then each entry string should be able to have enough space.
        -Obtain midpoint of entry. Subtract 1. This is how many spaces to go backwards
        starting from midpoint of entry. Insert string.
    */

    /*
        iterating through the string is tricky. We know that each entry has some 
        constant value say k. We have 2 borders and col - 1 spaces.
        How can it be possible to ensure that we only access entry points.

        - Detect border. If not border, attempt to access entry.
        - Obtain midpoint of entry.
            - Using starting index, go up by lenght of entry - 1
            to obtain the endpoint of entry space. Then insert entry begin
            and entry end into midpoint function.
        - Start at midpoint of entry.
        - Obtain entry string. 
        - Go to midpont of entry string and subtract 1. This is the distance
        needed to start in the entry point.
    */
    int string_index = 0;
    int column_entries = col;
    int row_two = column_length;
    int row_before_last = column_length * (char_row - 1);
    //The size of our largest string affects the end point of our enrtry.
    int entry_offset = largest_string - 1;
    for (int i = row_two; i < row_before_last; i++){
        n = i + 1;
        edge = n % column_length;
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
            //Obtain the start and end position for this specific entry.
            int entry_start = i;
            int entry_end = i + entry_offset;
            int entry_midpoint = midpoint(entry_start, entry_end);
            int string_start = midpoint(1, string_size) - 1;

            int entry_begin_offset = entry_midpoint - string_start;
            //printf("entry_start: %d\n", entry_begin_offset);
            //Fill the border string at the appropriate entry with the string.

            int j;
            for (j = 0; j < string_size; j++){
                border[entry_begin_offset + j] = temp_string[j];
            }
            column_entries--;
            //if(entry_midpoint == 0) entry_offset++;
            //Not sure why yet, adding 1 to offset always outputs correct result.
            i += entry_offset + 1;
            string_index++;
        }
    }

    /*
        Go back into the array and any '#' chars, replace with a space.
    */
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


int get_largest_stringf(float* float_array, int array_size){
    int size = 0;
    int current_string_size;
    char* float_string;
    for(int i = 0; i < array_size; i++){
        float_string = to_stringf(float_array[i]);
        current_string_size = size_of_string(float_string);
        if (current_string_size > size) size = current_string_size;
    }
    return size;
}

void fill_entries(int entry_start, int entry_offset, int string_size, char* entry_string, char* field){
    int stirng_size = size_of_string(entry_string);
    int entry_end = entry_start + (entry_offset - 1);
    int entry_midpoint = midpoint(entry_start, entry_end);
    //This should be safe because every entry is atleast the same size of the string.
    int string_start = midpoint(1, string_size) - 1;
    int start = entry_midpoint - string_start;

    for(int i = 0; i < string_size; i++){
        field[start + i] = entry_string[i];
    }

}