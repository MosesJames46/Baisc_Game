#include "../header_files/game_math.h"
#include <stdio.h>
#include <math.h>

Point distance(Point a, Point b){
    Point c;
    c.x = b.x - a.x;
    c.y = b.y - a.y;
    c.z = b.z - a.z;
    return c;
}

double magnitude(Point point){
    return sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
}

double square_magnitude(Point point){
    return point.x * point.x + point.y * point.y + point.z * point.z;
}

Point point_addition(Point A, Point B){
    Point C = {A.x + B.x, A.y + B.y, A.z + B.z};
    return C;
}

Point point_subtracition(Point A, Point B){
    Point C = {A.x - B.x, A.y - B.y, A.z - B.z};
    return C;
}

Point negate_point(Point point){
    Point negated_point = {-point.x, -point.y, -point.z};
    return negated_point;
}

void print_point(Point point){
    printf("{%lf, %lf, %lf}.", point.x, point.y, point.z);
}