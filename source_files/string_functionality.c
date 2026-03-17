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
    int temp_int = input;
    
    
    int size = 0;
    //obtain number of digits in the integer.
    int int_digit_count = 0;
    while (temp_int != 0){
        int_digit_count++;
        temp_int /= 10;
        size++;
    }

    //Because temp_int is currently 0, make it cut of the decimal portion of input again.
    temp_int = input;
    
    //Consider the sign of the input float.
    int sign = 1;
    if(input < 0){
        sign = -1;
        size++;
    }

    //[CREATE FLOAT STRING]
    //This is used later to determine the number to count for float string later.
    int float_digit_counter = 0;

    //Count how many decimal digits there are up to a max of 7.
    int max_decimal_places = 6;
    int float_to_int_result = 0;

    //Remove the integer from the float
    float temp_float = input - temp_int;
    //Negate temp_float to get positive temp_float if negative
    if (temp_float < 0) temp_float = -temp_float;
    printf("temp float: %f.\n", temp_float);
    //Used to ensure that no more than n amount of zeros can be within float consecutively
    int max_zeros = 4;
    int consecutive_zeros = 0;

    //Epsilon to count for smallest value.
    float epsilon = .000001f;
    while (max_decimal_places > 0 && temp_float >= epsilon){
        float_to_int_result *= 10;
        temp_float *= 10;

        //Obtain the integer digit from the float through c float to integer conversion.
        int obtained_int_value = temp_float;
        float_to_int_result += obtained_int_value;
        printf("Float result: %d.\n", float_to_int_result);
        if (float_to_int_result % 10 == 0){
            consecutive_zeros++;
        }else{
            consecutive_zeros = 0;
        }

        if (consecutive_zeros == max_zeros) break;
        
        temp_float -= obtained_int_value;
        max_decimal_places--;
        float_digit_counter++;
        size++;
    }

    //Remove trailing zeros.
    while (float_to_int_result % 10 == 0){
        float_to_int_result /= 10;
        size--;
    }

    float_to_int_result *= sign;
    //Size is determined by if there is a decimal and if the sign is negative.
    temp_int = input;
    char* int_string = to_stringi(temp_int);
    char* float_string = to_stringi(float_to_int_result);
    //printf("%d.\n", float_to_int_result);
    //printf("%s.\n", float_string);
    //Because of decimal increase.
    if (float_to_int_result > 0) size++;

    char* output_string = new_string(size);
    int index = 0;
    
    //Place appropriate negative value.
    if(sign < 1){
        output_string[0] = '-';
        index++;
    };

    //Using the index as the proper offest, we can always ensure the '.' gets placed in proper position.
    if(float_to_int_result){
        output_string[index + int_digit_count] = '.';
    }

    //Copy proper values into new string.
    int count = int_digit_count;
    int int_index = 0;
    while(count > 0){
        output_string[index + int_index] = int_string[index + int_index];
        int_index++;
        count--;
    }

    
    count = float_digit_counter;
    int float_index = 0;
    if(count > 0){
        //This is done because we need to skip over the decimal since the int_index stops one before it.
        int_index += 2;
        while(count > 0){
        //Use index again, sinze it stays unchange if it's 0 or 1 respectively, as an offset for the float_string.
        //Start at the int_index value. If there is a decimal, skip it. 
        output_string[int_index + float_index] = float_string[index + float_index];
        float_index++;
        count--;
        }
    }
    free(int_string);
    free(float_string);
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
