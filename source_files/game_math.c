#include "../header_files/game_math.h"
#include <stdio.h>
#include <math.h>

Vec3 distance(Vec3 a, Vec3 b){
    Vec3 c;
    c.x = b.x - a.x;
    c.y = b.y - a.y;
    c.z = b.z - a.z;
    return c;
}

double magnitude(Vec3 point){
    return sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
}

double square_magnitude(Vec3 point){
    return point.x * point.x + point.y * point.y + point.z * point.z;
}

Vec3 point_add(Vec3 A, Vec3 B){
    Vec3 C = {A.x + B.x, A.y + B.y, A.z + B.z};
    return C;
}

Vec3 point_sub(Vec3 A, Vec3 B){
    Vec3 C = {A.x - B.x, A.y - B.y, A.z - B.z};
    return C;
}

Vec3 point_neg(Vec3 point){
    Vec3 negated_point = {-point.x, -point.y, -point.z};
    return negated_point;
}

void point_print(Vec3 point){
    printf("{%lf, %lf, %lf}.", point.x, point.y, point.z);
}

Vec3 point_mul(Vec3 point, double scalar){
    Vec3 c = point;
    c.x *= scalar;
    c.y *= scalar;
    c.z *= scalar;
    return c;
}
Vec3 point_div(Vec3 point, double scalar){
    Vec3 c = point;
    c.x /= scalar;
    c.y /= scalar;
    c.z /= scalar;
    return c;
}

Vec3 point_mid(Vec3 A, Vec3 B){
    Vec3 c = point_add(A, B);
    c = point_div(c, 2.0f);
    return c;
}

Matrix2x2 Mat2x2_mul(Matrix2x2 A, Matrix2x2 B){
    Matrix2x2 C;
    C.m[0][0] = A.m[0][0] * B.m[0][0] + A.m[0][1] * B.m[1][0];
    C.m[0][1] = A.m[0][0] * B.m[0][1] + A.m[0][1] * B.m[1][1];

    C.m[1][0] = A.m[1][0] * B.m[0][0] + A.m[1][1] * B.m[1][0];
    C.m[1][1] = A.m[1][0] * B.m[0][1] + A.m[1][1] * B.m[1][1];
    
    return C;
}

float Mat2x2_det(Matrix2x2 A){
    return (A.m[0][0] * A.m[1][1] - A.m[1][0] * A.m[0][1]);
}