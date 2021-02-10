#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::m_Instance = nullptr;

InputHandler* InputHandler::GetInstance()
{
    if (m_Instance == nullptr)
    {
        m_Instance = new InputHandler();
    }
    return m_Instance;
}

void InputHandler::ListenForInput()
{
    //Returns array of every key that is not pressed (corresponding with 0)
    

    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            //QUITTING THE GAME
        case SDL_QUIT:
            //Game::GetInstance()->quitGame();
            break;

            //KEY PRESSES
        case SDL_KEYDOWN:
            KeyDown();
            break;

        case SDL_KEYUP:
            KeyUp();
            break;

            //MOUSE 
        case SDL_MOUSEBUTTONDOWN:
        {
            if (e.button.button == SDL_BUTTON_LEFT)
            {
                m_MouseButtonStates[LEFT] = true;
            }
            if (e.button.button == SDL_BUTTON_RIGHT)
            {
                m_MouseButtonStates[RIGHT] = true;
            }
        }
        case SDL_MOUSEBUTTONUP:
        {
            if (e.button.button == SDL_BUTTON_LEFT)
            {
                m_MouseButtonStates[LEFT] = false;
            }
            if (e.button.button == SDL_BUTTON_RIGHT)
            {
                m_MouseButtonStates[RIGHT] = false;
            }
        }
        }
    }
}

bool InputHandler::GetKeyDown(SDL_Scancode key_)
{
    if (m_KeyStates != 0)
    {
        if (m_KeyStates[key_] == 1)
            return true;
        else
            return false;
    }
    return false;
}

bool InputHandler::GetMouseButtonState(int button_)
{
    return m_MouseButtonStates[button_];
}

InputHandler::InputHandler()
    : m_KeyStates(0)
{
    for (int i = 0; i < 3; i++)
    {
        m_MouseButtonStates.push_back(false);
    }
}

void InputHandler::KeyUp()
{
    m_KeyStates = SDL_GetKeyboardState(0);
}

void InputHandler::KeyDown()
{
    std::cout << std::endl << "Key Pressed";
    m_KeyStates = SDL_GetKeyboardState(0);
}
