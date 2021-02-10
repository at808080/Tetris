#ifndef H_VECTOR2I
#define H_VECTOR2I

#include <cmath>

class Vector2i
{




public:
	Vector2i();
	Vector2i(int x_, int y_);
	int getX();
	int getY();
	void setX(int x_);
	void setY(int y_);
	void set(Vector2i v_);

	int getLength();

	Vector2i operator+(const Vector2i& second_Vect) const;
	Vector2i operator-(const Vector2i& second_Vect) const;
	Vector2i operator*(int scalar_) const;
	Vector2i operator/(int scalar_) const;

	friend Vector2i& operator+= (Vector2i& first_vect, Vector2i& second_vect);
	friend Vector2i& operator-= (Vector2i& first_vect, Vector2i& second_vect);
	friend Vector2i& operator*= (Vector2i& first_vect, int scalar_);
	friend Vector2i& operator/= (Vector2i& first_vect, int scalar_);

	bool operator==(const Vector2i&) const;

	const Vector2i& operator=(const Vector2i&);

	void normalise();

private:
	int x;
	int y;

};

#endif