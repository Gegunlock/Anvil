#include "Vector.h"

// Copy pasted from somewhere that I forgot
 Vector::Vector()
{
    x = y = z = 0.f;
}

 Vector::Vector(float ix, float iy, float iz)
{
    x = ix;
    y = iy;
    z = iz;
}

 Vector& Vector::operator = (const Vector &i)
{
    x = i.x;
    y = i.y;
    z = i.z;

    return *this;
}

 Vector& Vector::operator += (const Vector &i)
{
    x += i.x;
    y += i.y;
    z += i.z;

    return *this;
}

 Vector& Vector::operator -= (const Vector &i)
{
    x -= i.x;
    y -= i.y;
    z -= i.z;

    return *this;
}

 Vector& Vector::operator *= (const Vector &i)
{
    x *= i.x;
    y *= i.y;
    z *= i.z;

    return *this;
}

 Vector& Vector::operator *= (const float i)
{
    x *= i;
    y *= i;
    z *= i;

    return *this;
}

 Vector& Vector::operator /= (const Vector &i)
{
    x /= i.x;
    y /= i.y;
    z /= i.z;

    return *this;
}

 Vector& Vector::operator /= (const float i)
{
    x /= i;
    y /= i;
    z /= i;

    return *this;
}

 Vector Vector::operator + (const Vector &i) const
{
    return Vector(x + i.x, y + i.y, z + i.z);
}

 Vector Vector::operator - (const Vector &i) const
{
    return Vector(x - i.x, y - i.y, z - i.z);
}

 Vector Vector::operator * (const Vector &i) const
{
    return Vector(x * i.x, y * i.y, z * i.z);
}

 Vector Vector::operator * (const float &i) const
{
    return Vector(x * i, y * i, z * i);
}

 Vector Vector::operator / (const Vector &i) const
{
    return Vector(x / i.x, y / i.y, z / i.z);
}

 Vector Vector::operator / (const float &i) const
{
    return Vector(x / i, y / i, z / i);
}
