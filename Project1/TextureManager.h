#ifndef H_TEXTUREMANAGER
#define H_TEXTUREMANAGER

#include <iostream>
#include "SDL.h"
#include <map>
#include <SDL_image.h>

class TextureManager
{
public:
	static TextureManager* GetInstance();

	bool LoadTexture(std::string file_name_, std::string id_, SDL_Renderer* renderer_);
	void Draw(std::string id_, int x_, int y_, int width_, int height_, SDL_Renderer* renderer_, SDL_RendererFlip flip_);
	void DrawFrame(std::string id_, int x_, int y_, int width_, int height_, int row_, int frame_, SDL_Renderer* renderer_, SDL_RendererFlip flip_);


private:
	TextureManager();
	std::map<std::string, SDL_Texture*> m_Textures;
	static TextureManager* m_Instance;


};

#endif