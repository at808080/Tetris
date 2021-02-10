#include "Tetrino.h"

Tetrino::Tetrino(int width_, int height_, Vector2i pos_)
	: Matrix(width_, height_), m_Position(pos_)
{

}

Vector2i Tetrino::GetPos()
{
	return m_Position;
}

void Tetrino::SetPos(Vector2i pos_)
{
	m_Position = pos_;
}

void Tetrino::Down()
{
	m_Position.setY(m_Position.getY() + 1);
	std::cout << "Moving down " << std::endl;

}

void Tetrino::Left()
{
	m_Position.setX(m_Position.getX() - 1);
	std::cout << "Moving left " << std::endl;
}

void Tetrino::Right()
{
	m_Position.setX(m_Position.getX() + 1);
	std::cout << "Moving right " << std::endl;
}

void Tetrino::Update()
{
	if (InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_S))
	{
		Down();
	}
	if (InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
	{
		Left();
	}
	if (InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
	{
		Right();
	}
}