/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "Game.h"

Game* g_pGame;

//Screen dimension constants
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

int main(int argc, char* args[])
{
	g_pGame = new Game();

	g_pGame->Init("Game", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	while (g_pGame->Running())
	{
		//g_pGame->HandleEvents();
		g_pGame->Update();
		g_pGame->Render();
	}

	g_pGame->Clean();

	SDL_Quit();

	return 0;

}

