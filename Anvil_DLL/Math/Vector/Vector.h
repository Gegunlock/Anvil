#pragma once

// Copy pasted from somewhere that I forgot
class Vector
{
public:
	Vector();
	Vector(float, float, float);

	float&	operator [] (int);
	Vector&	operator =  (const Vector&);

	Vector&	operator += (const Vector&);
	Vector&	operator -= (const Vector&);
	Vector&	operator *= (const Vector&);
	Vector&	operator *= (const float);
	Vector&	operator /= (const Vector&);
	Vector&	operator /= (const float);

	Vector	operator +  (const Vector&) const;
	Vector	operator -  (const Vector&) const;

	Vector	operator *  (const Vector&) const;
	Vector	operator *  (const float&)  const;

	Vector	operator /  (const Vector&) const;
	Vector	operator /  (const float&)  const;

	float	x, y, z;
};
