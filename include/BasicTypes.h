#ifndef BASICTYPES_H
#define BASICTYPES_H

#include <iostream> //TODO: remove these three lines
using std::cout; 
using std::endl;

struct Colour {
    Colour(int _r = 0, int _g = 0, int _b = 0, int _a = 0)
        : r(_r), g(_g), b(_b), a(_a) {
    }
    int r;
    int g;
    int b;
    int a;
};

struct Vector2 {
    Vector2(float _x = 0, float _y = 0)
        : x(_x), y(_y) {
    }
    Vector2 operator* (float f) {
        return Vector2(x * f, y * f);
    }
    Vector2& operator+=(const Vector2& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    float x;
    float y;
};
#endif /* BASICTYPES_H */
