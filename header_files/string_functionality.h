#ifndef STRING_FUNCTIONALITY_HEADER
#define STRING_FUNCTIONALITY_HEADER
char* to_stringi(int input);
char* to_stringf(float input);
char* pos_to_stringi(int input);

char* new_string(int size);
void swap_char(char* a, char* b);
int size_of_string(char* a);


//Helper functions
static int digits_in_integer(int input);
static int decimal_as_ineger(float float_input, int max_zeros);
static int remove_trailing_zeros(int input);
static int leading_zerosf(float input);
static char* create_output_string(float float_input);

void fill_output_string(char* output_string, float float_value);

void fill_string_at(char* string_to_fill, char* other_string, int at);

#endif