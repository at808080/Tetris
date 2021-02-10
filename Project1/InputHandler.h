#ifndef H_InputHandler
#define H_InputHandler

#include <SDL.h>
#include <vector>

enum mouseButtons
{
	LEFT = 0,
	RIGHT = 1
};

class InputHandler
{
public:
	static InputHandler* GetInstance();

	void ListenForInput();

	//KEYS
	bool GetKeyDown(SDL_Scancode code_);

	//MOUSE
	bool GetMouseButtonState(int button_);	

private:
	InputHandler();
	static InputHandler* m_Instance;

	//KEYS
	void KeyUp();
	void KeyDown();
	const Uint8* m_KeyStates; //array to store states of keys

	//MOUSE
	std::vector<bool> m_MouseButtonStates;

};

#endif