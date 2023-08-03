#ifndef PIZE_CORE_MATH_VECMATH_MATRIX_MATRIX_4F
#define PIZE_CORE_MATH_VECMATH_MATRIX_MATRIX_4F

static const char m00 = 0, m10 = 4, m20 = 8 , m30 = 12;
static const char m01 = 1, m11 = 5, m21 = 9 , m31 = 13;
static const char m02 = 2, m12 = 6, m22 = 10, m32 = 14;
static const char m03 = 3, m13 = 7, m23 = 11, m33 = 15;

class Matrix4f{

public:

    GLfloat val[16] {};

    Matrix4f(){
        val[m00] = 1;
        val[m11] = 1;
        val[m22] = 1;
        val[m33] = 1;
    }

    Matrix4f *identity(){
        val[m00] = 1; val[m10] = 0; val[m20] = 0; val[m30] = 0;
        val[m01] = 0; val[m11] = 1; val[m21] = 0; val[m31] = 0;
        val[m02] = 0; val[m12] = 0; val[m22] = 1; val[m32] = 0;
        val[m03] = 0; val[m13] = 0; val[m23] = 0; val[m33] = 1;

        return this;
    }

    Matrix4f *toOrthographic(float x, float y, float width, float height){
        identity();

        val[m00] = 2 / width;
        val[m11] = 2 / height;
        val[m22] = -2;

        val[m30] = -(x * 2 + width) / width;
        val[m31] = -(y * 2 + height) / height;
        val[m32] = -1;

        return this;
    }

};

#endif