#include "Vector2i.h"
Vector2i::Vector2i()
{
	x = 0;
	y = 0;
}
Vector2i::Vector2i(int x_, int y_)
{
	x = x_;
	y = y_;
}

int Vector2i::getX()
{
	return this->x;
}

int Vector2i::getY()
{
	return this->y;
}

void Vector2i::setX(int x_)
{
	this->x = x_;
}

void Vector2i::setY(int y_)
{
	this->y = y_;
}

void Vector2i::set(Vector2i v_)
{
	setX(v_.getX());
	setY(v_.getY());
}

int Vector2i::getLength()
{
	return sqrt(x * x + y * y);
}

Vector2i Vector2i::operator+(const Vector2i& second_Vect) const
{
	Vector2i tempVect(x + second_Vect.x, y + second_Vect.y);
	return tempVect;
}

Vector2i Vector2i::operator-(const Vector2i& second_Vect) const
{
	Vector2i tempVect(x - second_Vect.x, y - second_Vect.y);
	return tempVect;
}

Vector2i Vector2i::operator*(int scalar_) const
{
	Vector2i tempVect(x * scalar_, y * scalar_);
	return tempVect;
}

Vector2i Vector2i::operator/(int scalar_) const
{
	Vector2i tempVect(x / scalar_, y / scalar_);
	return tempVect;
}

bool Vector2i::operator==(const Vector2i& other_vect) const
{
	if (x == other_vect.x && y == other_vect.y)
	{
		return true;
	}
	return false;
}

const Vector2i& Vector2i::operator=(const Vector2i& other_vect)
{
	if (this != &other_vect)
	{
		x = other_vect.x;
		y = other_vect.y;
	}
	return *this;
}

void Vector2i::normalise()
{
	int l = getLength();
	if (l > 0)
	{
		(*this) /= l;
	}
}

Vector2i& operator+=(Vector2i& first_vect, Vector2i& second_vect)
{
	first_vect.x += second_vect.x;
	first_vect.y += second_vect.y;
	return first_vect;
}

Vector2i& operator-=(Vector2i& first_vect, Vector2i& second_vect)
{
	first_vect.x -= second_vect.x;
	first_vect.y -= second_vect.y;
	return first_vect;
}

Vector2i& operator*=(Vector2i& first_vect, int scalar_)
{
	first_vect.x *= scalar_;
	first_vect.y *= scalar_;
	return first_vect;
}

Vector2i& operator/=(Vector2i& first_vect, int scalar_)
{
	first_vect.x /= scalar_;
	first_vect.y /= scalar_;
	return first_vect;
}
