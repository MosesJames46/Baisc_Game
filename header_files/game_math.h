
/*
Math particular to a game.
*/
#ifndef GAME_MATH_HEADER
#define GAME_MATH_HEADER
typedef struct Vec3_struct Vec3;
struct Vec3_struct{
    float x;
    float y;
    float z;
};

typedef struct Matrix2x2_Struct Matrix2x2;
struct Matrix2x2_Struct{
    float** m;
};

Vec3 distance(Vec3 u, Vec3 v);

double magnitude(Vec3 point);
double square_magnitude(Vec3 point);

Vec3 point_add(Vec3 u, Vec3 v);
Vec3 point_sub(Vec3 u, Vec3 v);
Vec3 point_neg(Vec3 point);

Vec3 point_mul(Vec3 u, double scalar);
Vec3 point_div(Vec3 u, double scalar);

Vec3 point_mid(Vec3 u, Vec3 v);

void print_point(Vec3 u);

Matrix2x2 Mat2x2_mul(Matrix2x2 A, Matrix2x2 B);
float Mat2x2_det(Matrix2x2 A);
float Mat2x2_trace(Matrix2x2 A);

#endif