#ifndef H_GAME
#define H_GAME

#include "SDL.h"
#include <iostream>
#include <SDL_image.h>
#include "TextureManager.h"
#include "InputHandler.h"
#include "Clock.h"
#include "Matrix.h"
#include "Tetrino.h"
#include "Board.h"
#include "Settings.h"

enum DifficultySetting
{
	Imbecile = 0,
	Battler = 1,
	Joe = 2,
	HotShot = 3,
	Prodigy = 4
};

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title_, int xpos_, int ypos_, int width_, int height_, int flags_);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool Running();

	void UpdateCurrentTetrino();
	void NewTetrino();


private:	
	bool m_Running;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;


	SDL_Surface* m_Surface;
	SDL_Texture* m_Texture;
	SDL_Rect m_RectSource;
	SDL_Rect m_RectDest; 

	Matrix* m_Board;
	Matrix* m_CurrentPiece;
	Tetrino* m_CurrentTetrino;
	Board* m_Boardd;

	int xx;
	int framestart;
	int last;
	int time;
	//TextureManager m_TextureManager;

	int lastKeyTime;
	int keyTime;

	int m_Tetrinos [4][4][2] = { {{1, 0}, {2, 0}, {3, 0}, {3, 1}},
								 {{1, 0}, {2, 0}, {3, 0}, {2, 1}},
							     {{1, 0}, {2, 0}, {1, 1}, {2, 1}},
							     {{0, 0}, {1, 0}, {2, 0}, {3, 0}} };

	Settings m_SettingsChoices[5];
	DifficultySetting m_CurrentSettingsChoice;

	int next_tetrino;
	

};

#endif