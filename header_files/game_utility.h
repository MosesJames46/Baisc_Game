/*
Utility functions declared to assist with game functionality.
3/13/2026:
    -If you don't compile each source, you'll get undefined reference for some reason.
*/
#ifndef GAME_UTILITY_HEADER
#define GAME_UTILITY_HEADER
void allocate_2Darray(int width, int height, int*** pointer_to_array);
int deallocate_2Darray(int width, int height, int** pointer_to_array);

void allocate_1Darray(int size, int** pointer_to_array);
void deallocate_1Darray(int* ponter_to_array);
#endif