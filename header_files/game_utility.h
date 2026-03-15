/*
Utility functions declared to assist with game functionality.
3/14/2026: 
    - Utility functions have consistent argument lists. 

3/13/2026:
    -If you don't compile each source, you'll get undefined reference for some reason.
*/
#ifndef GAME_UTILITY_HEADER
#define GAME_UTILITY_HEADER
void allocate_2Darray(float*** pointer_to_array, int width, int height);
int deallocate_2Darray(float** pointer_to_array, int width, int height);

void allocate_1Darray(float** pointer_to_array, int size);
void deallocate_1Darray(float* ponter_to_array);

void input_array(float*** array, int width, int height);
void output_array(float*** array, int width, int height);
#endif