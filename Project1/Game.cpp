#include "Game.h"

Game::Game() : m_Running(false)
{
	/*xx = 10;

	m_Board = new Matrix(10, 20);
	m_Board->InitialiseFalse();

	m_CurrentPiece = new Matrix(4, 4);
	m_CurrentPiece->InitialiseFalse();
	m_CurrentPiece->SetAtIndex(1, 1, true);
	m_CurrentPiece->SetAtIndex(1, 2, true);
	m_CurrentPiece->SetAtIndex(2, 1, true);
	m_CurrentPiece->SetAtIndex(2, 2, true);

	m_CurrentTetrino = new Tetrino(4, 4, 0);
	m_CurrentTetrino->InitialiseFalse();
	m_CurrentTetrino->SetAtIndex(1, 0, true);
	m_CurrentTetrino->SetAtIndex(2, 0, true);
	m_CurrentTetrino->SetAtIndex(3, 0, true);
	m_CurrentTetrino->SetPos(Vector2i(2, 2));

	m_Board->SetOccupant(4, 8, *m_CurrentPiece, true);
	m_Board->SetOccupant(1, 1, *m_CurrentTetrino, true);*/

	m_Boardd = new Board(10, 20);
	m_Boardd->InitialiseFalse();

	m_CurrentTetrino = new Tetrino(4, 4, Vector2i(0, 8));
	m_CurrentTetrino->InitialiseFalse();
	m_CurrentTetrino->SetAtIndex(1, 0, true);
	m_CurrentTetrino->SetAtIndex(2, 0, true);
	m_CurrentTetrino->SetAtIndex(3, 0, true);
	m_CurrentTetrino->SetAtIndex(3, 1, true);
	m_CurrentTetrino->SetPos(Vector2i(2, 5));

	m_Boardd->SetOccupant(*m_CurrentTetrino, true);

	time = 0;
	last = 0;

	keyTime = 0;
	lastKeyTime = 0;

}

Game::~Game()
{

}

void Game::Init(const char* title_, int xpos_, int ypos_, int width_, int height_, int flags_)
{
	m_Running = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		this->m_Window = SDL_CreateWindow(title_, xpos_, ypos_, width_, height_, flags_);

		if (m_Window != nullptr)
		{
			std::cout << "Successful init ";
			m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);

			if (m_Renderer != nullptr)
			{
				std::cout << "Renderer created successfully";
				SDL_SetRenderDrawColor(m_Renderer, 10, 100, 10, 255);
			}
			else
			{
				std::cout << "Renderer could not be created ";
				m_Running = false;
			}
		}

		TextureManager::GetInstance()->LoadTexture("Assets/Green.png", "GreenTile", m_Renderer);
		TextureManager::GetInstance()->LoadTexture("Assets/Blue.png", "BlueTile", m_Renderer);
		TextureManager::GetInstance()->LoadTexture("Assets/Red.png", "RedTile", m_Renderer);
	}
	else
	{
		std::cout << "Could not init ";
		m_Running = false;
	}
}

void Game::HandleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_Running = false;
			break;

		default:
			break;
		}

	}

}

void Game::Update()
{
	InputHandler::GetInstance()->ListenForInput();

	time += SDL_GetTicks() - last;
	last = SDL_GetTicks();
	//std::cout << std::endl << " TIME : " << time << " " << SDL_GetTicks();

	keyTime += SDL_GetTicks() - lastKeyTime;
	lastKeyTime = SDL_GetTicks();
	if (keyTime > 200)
	{
		UpdateCurrentTetrino();
	}

	if (time > 800)
	{
		time = 0;
		if (m_Boardd->CheckForCollision(*m_CurrentTetrino, Down) == false)
		{
			m_Boardd->SetOccupant(*m_CurrentTetrino, false);
			m_CurrentTetrino->Down();
			m_Boardd->SetOccupant(*m_CurrentTetrino, true);
		}
		else
		{
			while (m_Boardd->CheckForFullRow(19))
			{
				m_Boardd->RemoveFullRow(19);
			}
			NewTetrino();
		}
		
	}

	

}

void Game::Render()
{
	SDL_RenderClear(m_Renderer);

	//m_Matrix.

	for (int i = 0; i < m_Boardd->Width(); i++)
	{
		for (int j = 0; j < m_Boardd->Height(); j++)
		{
			if (m_Boardd->GetAtIndex(i, j) == false) TextureManager::GetInstance()->Draw("BlueTile", 32*i, 32*j, 32, 32, m_Renderer, SDL_FLIP_NONE);
			else TextureManager::GetInstance()->Draw("RedTile", 32 * i, 32 * j, 32, 32, m_Renderer, SDL_FLIP_NONE);
		}
	}

	SDL_RenderPresent(m_Renderer);
}




void Game::Clean()
{
	std::cout << " Game clean";
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
	SDL_Quit();
}

bool Game::Running()
{
	return m_Running;
}

void Game::UpdateCurrentTetrino()
{
	if ((InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_S)
		|| InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_DOWN))
		&& m_Boardd->CheckForCollision(*m_CurrentTetrino, Down) == false)
	{
		m_Boardd->SetOccupant(*m_CurrentTetrino, false);
		m_CurrentTetrino->Down();
		m_Boardd->SetOccupant(*m_CurrentTetrino, true);
		keyTime = 0;
	}
	if ((InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_A)
		|| InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_LEFT))
		&& m_Boardd->CheckForCollision(*m_CurrentTetrino, Left) == false)
	{
		m_Boardd->SetOccupant(*m_CurrentTetrino, false);
		m_CurrentTetrino->Left();
		m_Boardd->SetOccupant(*m_CurrentTetrino, true);
		keyTime = 0;
	}
	if ((InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_D)
		|| InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_RIGHT))
		&& m_Boardd->CheckForCollision(*m_CurrentTetrino, Right) == false)
	{
		m_Boardd->SetOccupant(*m_CurrentTetrino, false);
		m_CurrentTetrino->Right();
		m_Boardd->SetOccupant(*m_CurrentTetrino, true);
		keyTime = 0;
	}

	if (InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE)
		&& m_Boardd->CheckForCollisionRotation(*m_CurrentTetrino) == false)
	{
		m_Boardd->SetOccupant(*m_CurrentTetrino, false);
		m_CurrentTetrino->RotateAntiClockwise();
		m_Boardd->SetOccupant(*m_CurrentTetrino, true);
		keyTime = 0;
	}
}

void Game::NewTetrino()
{
	delete m_CurrentTetrino;
	m_CurrentTetrino = new Tetrino(4, 4, Vector2i(0, 0));
	m_CurrentTetrino->InitialiseFalse();
	m_CurrentTetrino->SetAtIndex(1, 0, true);
	m_CurrentTetrino->SetAtIndex(2, 0, true);
	m_CurrentTetrino->SetAtIndex(3, 0, true);
	m_CurrentTetrino->SetAtIndex(3, 1, true);
	m_CurrentTetrino->SetPos(Vector2i(2, 2));

	m_Boardd->SetOccupant(*m_CurrentTetrino, true);
}
