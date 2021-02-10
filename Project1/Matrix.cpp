#include "Matrix.h"

Matrix::Matrix(int width_, int height_)
{
	m_Width = width_;
	m_Height = height_;
	m_Matrix = new bool* [height_];
	for (int i = 0; i < height_; i++)
	{
		m_Matrix[i] = new bool[width_];
	}
	InitialiseFalse();
}

Matrix::~Matrix()
{
}

void Matrix::InitialiseFalse()
{
	for (int i = 0; i < m_Width; i++)
	{
		for (int j = 0; j < m_Height; j++)
		{
			//std::cout << " matrix " << i << " " << j << " ";
			m_Matrix[i][j] = false;
		}
	}
}

int Matrix::Width()
{
	return m_Width;
}

int Matrix::Height()
{
	return m_Height;
}

bool Matrix::GetAtIndex(int x_, int y_)
{
	if (x_ >= 0 && x_ < m_Width && y_ >= 0 && y_ < m_Height)
	{
		return m_Matrix[x_][y_];
	}
	else
	{
		return false;
	}
}

void Matrix::SetAtIndex(int x_, int y_, bool b_)
{
	m_Matrix[x_][y_] = b_;
}

void Matrix::RotateAntiClockwise()
{
	for (int i = 0; i < (m_Width + 1) / 2; i++) {
		for (int j = 0; j < m_Height / 2; j++) {
			int temp = m_Matrix[m_Width - 1 - j][i];
			m_Matrix[m_Width - 1 - j][i] = m_Matrix[m_Width - 1 - i][m_Height - j - 1];
			m_Matrix[m_Width - 1 - i][m_Height - j - 1] = m_Matrix[j][m_Width - 1 - i];
			m_Matrix[j][m_Width - 1 - i] = m_Matrix[i][j];
			m_Matrix[i][j] = temp;
		}
	}
}
