#include "TextureManager.h"
TextureManager* TextureManager::m_Instance = nullptr;

TextureManager::TextureManager()
{

}

TextureManager* TextureManager::GetInstance()
{
    if (m_Instance == nullptr)
    {
        m_Instance = new TextureManager();
    }
    return m_Instance;
}

bool TextureManager::LoadTexture(std::string file_name_, std::string id_, SDL_Renderer* renderer_)
{
    bool success = true;

    SDL_Surface* temp_surface = IMG_Load(file_name_.c_str());

    if (temp_surface == nullptr)
    {
        success = false;
    }

    if (success)
    {
        SDL_Texture* texture_ = SDL_CreateTextureFromSurface(renderer_, temp_surface);
        SDL_FreeSurface(temp_surface);

        if (texture_ != nullptr)
        {
            m_Textures[id_] = texture_;
            std::cout << "Successfully loaded texture " << id_;
        }
    }
    

    return success;
}

void TextureManager::Draw(std::string id_, int x_, int y_, int width_, int height_, SDL_Renderer* renderer_, SDL_RendererFlip flip_)
{
    SDL_Rect m_RectSource;
    SDL_Rect m_RectDest;

    m_RectSource.x = 0;
    m_RectSource.y = 0;
    SDL_QueryTexture(m_Textures[id_], NULL, NULL, &m_RectSource.w, &m_RectSource.h);
    m_RectDest.x = x_;
    m_RectDest.y = y_;
    m_RectDest.w = width_;//m_RectSource.w ;
    m_RectDest.h = height_; // m_RectSource.h;

    SDL_RenderCopyEx(renderer_, m_Textures[id_], &m_RectSource, &m_RectDest, 0, 0, SDL_FLIP_NONE);
}

void TextureManager::DrawFrame(std::string id_, int x_, int y_, int width_, int height_, int row_, int frame_, SDL_Renderer* renderer_, SDL_RendererFlip flip_)
{
}
