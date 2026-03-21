#include "../header_files/string_functionality.h"
#include <stdlib.h>
#include <stdio.h>

char* to_stringi(int input){
    int size = 0;
    int temp = input;
    int sign = 1;

    //Size gets increased because we need to make space for a negative sign.
    if (temp < 0){
        sign = -1;
        temp *= -1;
        //printf("The temp value if it's less than zero: %d.\n", temp);
        size++;
    }
  
    //Increase the size of the soon to be string for every digit we find
    while (temp != 0){
        size++;
        temp /= 10;
    }

    //Don't know if we should continue having this malloced char* or just return a char pointer with a certain size.
    //printf("Obtaining the proper size: %d.\n", size);
    char* string = new_string(size);
    //Resusing the input value since temp should be zero at this point.
    temp = input * sign;
    //printf("The temp value when multiplying input by sign: %d.\n", temp);
    char temp_c;
    
    int index = 0;
    if (sign ==- 1){
        string[0] = '-';
        index++;
    }
    //printf("Test if index works properly based on sign value: %d.\n", index);
    //printf("Show curret string to test if negative sign gets added: %s.\n", string);
    //Everything in the char* gets placed in reversed order.
    while (temp != 0){
        temp_c = temp % 10;
        temp /= 10;
        string[index] = temp_c + 48;
        index++;
    }
    //printf("The current string after it's reverse order has been added: %s.\n", string);
    int begin = 0;
    int end = size - 1;

    if(sign == -1) begin++;
    //Ensure that values are placed in proper order after.
    while(begin < end){
        char t = string[begin];
        swap_char(&string[begin], &string[end]);
        begin++;
        end--;
    }

    return string;
}

char* to_stringf(float input){
   
    char* output_string = create_output_string(input);

    return output_string;
}

char* new_string(int size){
    //size + 1 consideres the null terminator.
    char* string = malloc(sizeof(char) * size + 1);
    string[size] = '\0';
    //Initialize string;
    for (int i = 0; i < size; i++){
        string[i] = ' ';
    }
    return string;
}

void swap_char(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int size_of_string(char* a){
    /*
        Given a c_string, obtain the size given the string has a null terminator.
    */

    int size = 0;
    while (*a++ != '\0'){
        size++;
    }
    return size;
}


int leading_zerosf(float input){
    /*
        Given a floating point input, return the number of zeros that follow
        immediately after a decimal up to the first non-zero number. 
    */

    //Separate integer from float.
    int temp = input;
    input -= temp;

    if (input == 0) input += temp;

    int count = 0;
    temp = 0;
    while(input != 0 && temp == 0 && count < 8){
        temp = (input *= 10);
        count++;
    }
    return count - 1;
}


int digits_in_integer(int input){
    /*
        Count total digits within an integer input.
    */
    int count = 0;
    while (input != 0){
        count++;
        input /= 10;
    }
    return count;
}


int decimal_as_integer(float float_input, int max_zeros){
    /*
        Creates an integer without any leading zeros.
        Removes trailing zeros.
        Ensures positive output.
    */
   
    //Esnure float is positive and removes the integer before the decimal.
    if (float_input < 0) float_input *= -1;
    int integer_of_float = float_input;
    float_input = float_input - integer_of_float;

    const float epsilon = .00001f;
    int result = 0;

    while (max_zeros > 0 && float_input >= epsilon){
        float_input *= 10;
        int temp_result = float_input;
        result *= 10;

        result += temp_result;
        float_input -= temp_result;

        max_zeros--;
    }

    result = remove_trailing_zeros(result);
    return result;
}

int remove_trailing_zeros(int input){
    while (input % 10 == 0 && input != 0){
        input /= 10;
    }
    return input;
}

int size_of_float(float input){

    /*
        Get size of output string based on a float input. This is used when 
        wanting to create an string not when a string is already made.
    */

    int size = 0;
    int integer_size = digits_in_integer((int)input);
    int leading_zeros = leading_zerosf(input);
    int float_size = digits_in_integer(decimal_as_integer(input, 6)) + leading_zeros;
    
    /*
        These respectively check for negative sign and decimal.
    */
    if(input < 0) size++;
    if(float_size) size++;

    size += integer_size + float_size;
    return size;
}

char* create_output_string(float float_value){
    int size = size_of_float(float_value);
    char* output_string = new_string(size);
    fill_output_string(output_string, float_value);
    return output_string;
}

void fill_output_string(char* output_string, float float_value){

    /*
        Obtains necessary data to fill in the output string.
    */
    int leading_zeros = leading_zerosf(float_value);
    int deci_to_integer = decimal_as_integer(float_value, 6);


    char* integer_string = pos_to_stringi(float_value);
    char* float_string = pos_to_stringi(deci_to_integer);


    int size = size_of_float(float_value);
    /*
        os = output_string
        is = integer_string
        fs = float_string
    */
    int os_index = 0;
    int is_index = 0;
    int fs_index = 0;

    //Place negative char if float is negative. 
    if (float_value < 0) {
        output_string[0] = '-';
        os_index++;
    }

    fill_string_at(output_string, integer_string, os_index);
    os_index += digits_in_integer(float_value);

    //Place decimal char if float is negative.
    if (deci_to_integer){
        output_string[os_index] = '.';
        os_index++;
    }

    while(leading_zeros){
        output_string[os_index] = '0';
        leading_zeros--;
        os_index++;
    }

    fill_string_at(output_string, float_string, os_index);
    free(integer_string);
    free(float_string);
}

void fill_string_at(char* string_to_fill, char* other_string, int at){
    int other_index = 0;
    while(string_to_fill[at] != '\0' && other_string[other_index] != '\0'){
        string_to_fill[at] = other_string[other_index];
        other_index++;
        at++;
    }
}

char* pos_to_stringi(int float_input){
    if (float_input < 0) float_input *= -1;
    return to_stringi(float_input);
}