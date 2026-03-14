
/*
Math particular to a game.
*/
#ifndef GAME_MATH_HEADER
#define GAME_MATH_HEADER
typedef struct Point_struct Point;
struct Point_struct{
    double x;
    double y;
    double z;
};

Point distance(Point a, Point b);

double magnitude(Point point);
double square_magnitude(Point point);

Point point_addition(Point A, Point B);
Point point_subtracition(Point A, Point B);
Point negate_point(Point point);

void print_point(Point Point);

#endif