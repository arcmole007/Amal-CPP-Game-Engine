#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>


//class Vector2D is like in godot where there are
//velocity between x and y
class Vector2D
{

public:
    float x;
    float y;

    Vector2D();
    Vector2D(float x, float y);

    Vector2D& Add(const Vector2D& vec);
    Vector2D& Subtract(const Vector2D& vec);
    Vector2D& Multiply(const Vector2D& vec);
    Vector2D& Divide(const Vector2D& vec);

    friend Vector2D& operator+(Vector2D& vector_1, const Vector2D& vector_2);
    friend Vector2D& operator-(Vector2D& vector_1, const Vector2D& vector_2);
    friend Vector2D& operator*(Vector2D& vector_1, const Vector2D& vector_2);
    friend Vector2D& operator/(Vector2D& vector_1, const Vector2D& vector_2);

    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);

    Vector2D& operator*(const int& i);
    Vector2D& Zero();

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};

#endif //VECTOR2D_H