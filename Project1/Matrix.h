#ifndef H_MATRIX
#define H_MATRIX

#include <iostream>

class Matrix
{
public:
	Matrix(int width_, int height_);
	~Matrix();
	void InitialiseFalse();
	int Width();
	int Height();
	bool GetAtIndex(int x_, int y_);
	void SetAtIndex(int x_, int y_, bool b_);
	//void SetOccupant(int x_, int y_, Matrix child_, bool b_);
	void RotateAntiClockwise();

protected:
	int m_Width;
	int m_Height;
	
	bool** m_Matrix;

	
};

#endif