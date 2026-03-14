
/*
Math particular to a game.
*/
#ifndef GAME_MATH_HEADER
#define GAME_MATH_HEADER
typedef struct Point_struct Point;
struct Point_struct{
    int x;
    int y;
    int z;
};

Point distance(Point a, Point b);
void print_point(Point Point);

#endif