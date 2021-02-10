#include "Board.h"

Board::Board(int width_, int height_) : Matrix(width_, height_)
{
	
}

void Board::SetOccupant(Tetrino t_, bool b_)
{
	//std::cout << std::endl << "Setting occupant at " << t_.GetPos().getX() << " " << t_.GetPos().getY() << " " << t_.Width() << " " << t_.Height();
	for (int i = t_.GetPos().getX(); i - t_.GetPos().getX() < t_.Width(); i++)
	{
		for (int j = t_.GetPos().getY() ; j - t_.GetPos().getY() < t_.Height(); j++)
		{
			//std::cout << std::endl << "current:  " << i << " " << j << " ";
			if (t_.GetAtIndex(i - t_.GetPos().getX(), j - t_.GetPos().getY()) == true)
			{
				m_Matrix[i][j] = b_;
			}
		}
	}
}

bool Board::CheckForCollision(Tetrino t_, CollisionDirection d_)
{
	bool coll_ = false;

	int x_;
	int y_;

	Vector2i v_;

	switch (d_)
	{
	case Down:
		x_ = t_.GetPos().getX();
		y_ = t_.GetPos().getY() + 1;
		v_ = Vector2i(0, 1);
		break;

	case Left:
		x_ = t_.GetPos().getX() - 1;
		y_ = t_.GetPos().getY();
		v_ = Vector2i(-1, 0);
		break;

	case Right:
		x_ = t_.GetPos().getX() + 1;
		y_ = t_.GetPos().getY();
		v_ = Vector2i(1, 0);
		break;
	default:
		x_ = 0;
		y_ = 0;
	}

	std::cout << std::endl << "Checking for collision, v_ = " << v_.getX() << " " << v_.getY();
	
	for (int i = x_; coll_ == false && i - x_ < t_.Width(); i++)
	{
		for (int j = y_; coll_ == false && j - y_ < t_.Height(); j++)
		{
			std::cout << std::endl << "Within tetrino: " << i - x_ << " " << j - y_ << " " << t_.GetAtIndex(i - x_, j - y_);
			if (t_.GetAtIndex(i - x_, j - y_) == true 
				&& t_.GetAtIndex(i - x_ + v_.getX(), j - y_ + v_.getY()) == false)
			{
				std::cout << std::endl << "Edge tile of tetrino at " << i - x_ << " " << j - y_ << " ";
				if (j >= m_Height
					|| j < 0
					|| i >= m_Width
					|| i < 0
					|| m_Matrix[i][j] == true)
				{
					coll_ = true;
				}
			}
		}
	}
	if (coll_ == true) std::cout << std::endl << "COLLISION";
	return coll_;
}

bool Board::CheckForCollisionRotation(Tetrino t_)
{
	if (t_.GetPos().getX() == 0 
		|| t_.GetPos().getX() >= 6
		|| t_.GetPos().getY() == 0 
		|| t_.GetPos().getY() >= 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::CheckForFullRow(int y_)
{
	bool fullrow = true;

	for (int i = 0; fullrow && i < m_Width; i++)
	{
		if (m_Matrix[i][y_] == false) fullrow = false;
	}

	return fullrow;
}

void Board::RemoveFullRow(int y_)
{
	for (int j = y_; j > 0; j--)
	{
		for (int i = 0; i < m_Width; i++)
		{
			m_Matrix[i][j] = m_Matrix[i][j - 1];
		}
	}
	
}