#include "../header_files/game_math_utility.h"
#include <stdlib.h>
#include <stdio.h>

void init_mat(float*** mat, int width, int height){
    *mat = malloc(sizeof(float*) * height);
    for(int i = 0; i < 2; i++){
        (*mat)[i] = malloc(sizeof(float) * width);
    }
}

void destroy_mat(float** mat, int width, int height){
        for (int i = 0; i < height; i++){
            free(mat[i]);
        }
        free(mat);
}
