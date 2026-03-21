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
    char border[1024];

    //Get all floats in matrix
    float float_array[row * col];
    get_floats_from_matrix(float_array, *screen, row, col);

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



    //Make sure there is a counter for current string to input into border.
    init_border(border, char_row, column_length);
   /*
    Go back through char array and input strings.
   */
 
    fill_border(string_array, border, row, col, column_length);

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
    /*
        Given an array of floats, obtain the the float that holds the largest string.
    */

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

void init_border(char* border, int rows, int columns){
    /*
        Given an input array, fill with initial values.
        Borders are determine by edges. 
    */

    /*
        When placing chars into the string, we need to know when we are on
        the edges of the array.
        Edge definition: 
            - Let i be index. Then n = i + 1. Then edge = n % column. If edge == 0 or edge == 1 then we are on edge. 
        A top/bottom edge should be:
            - edge = i / row_width. If edge == 0 || edge == number_of_rows, then we are on edge.

        If we are on an edge place the appropriate border char.
    */
    int current_string = 0;
    int dimenson_of_border = rows * columns;
    int edge;
    int n;

    for (int i = 0; i < dimenson_of_border; i++){
        n = i + 1;
        edge = n % columns;
        int bottom_edge = rows - 1;
        int border_dash = i / columns;
        //border_dash == 0 || border_dash == bottom_edge
        if (border_dash == 0 || border_dash == bottom_edge){
            border[i] ='-';
         }else if(edge == 0 || edge == 1){
            border[i] = '|';
         }else{
            border[i] = '#';
         }
    }
}

void get_floats_from_matrix(float* float_array, float** matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            float_array[(i * cols) + j] = matrix[i][j];
        }
    }
}


int get_edge(int zero_based_index, int columns){
    return (zero_based_index + 1) % columns;
}

void fill_entry(char* string, char* border, int string_index, int border_index, int column_entries, int entry_offset){
        
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

        int string_size = size_of_string(string);
        //Obtain the start and end position for this specific entry.
        int entry_start = border_index;
        int entry_end = border_index + entry_offset;
        
        int entry_midpoint = midpoint(entry_start, entry_end);
        int string_start = midpoint(1, string_size) - 1;

        int entry_begin_offset = entry_midpoint - string_start;
        //printf("entry_start: %d\n", entry_begin_offset);
        //Fill the border string at the appropriate entry with the string.

        int j;
        for (j = 0; j < string_size; j++){
            border[entry_begin_offset + j] = string[j];
        }
}

void fill_border(char** string_array, char* border, int rows, int cols, int columns){
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

    
    int column_entries = cols;
    int start = columns;
    /*
        The rows input only represent whats in the original matrix.
        To get the correct number of rows in the border char, we need to add 2.
        To properly account for the second to the last row, we subtract 1.
        Full expression will be rows + 1.
    */
    int end = columns * (rows + 1);
    int edge;

    //sarr_index -> string array index
    int sarr_index = 0;
    printf("Start: %d\n", start);
    printf("End: %d\n", end);
    //Represents the size of each entry value. Minues 1 because a size of n will have index n-1 for last element
    int entry_offset = get_largest_string(string_array, rows * cols) - 1;
    for(int i = start; i < end; i++){
        printf("Current i: %d\n", i);
        edge = get_edge(i, columns);
        printf("Edge: %d\n", edge);
        if (column_entries == 0){
            while (border[i] == '#'){
                i++;
                printf("Current char: %d\n", i);
            }
            column_entries = cols;
        }else if (edge != 1 && edge != 0 && sarr_index < rows * cols){
            fill_entry(string_array[sarr_index], border, sarr_index, i, column_entries, entry_offset);
            column_entries--;
            //if(entry_midpoint == 0) entry_offset++;
            //Not sure why yet, adding 1 to offset always outputs correct result.
            i += entry_offset + 1;
            sarr_index++;
        }

    }
}

int get_largest_string(char** string_array, int size){
    int largest = 0;
    for (int i = 0; i < size; i++){
        int current = size_of_string(string_array[i]);
        if (current > largest) largest = current;
    }
    return largest;
}