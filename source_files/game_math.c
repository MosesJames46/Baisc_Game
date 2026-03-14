#include "../header_files/game_math.h"
#include <stdio.h>

Point distance(Point a, Point b){
    Point c;
    c.x = b.x - a.x;
    c.y = b.y - a.y;
    c.z = b.z - a.z;
    return c;
}

void print_point(Point point){
    printf("{%d, %d, %d}.", point.x, point.y, point.z);
}