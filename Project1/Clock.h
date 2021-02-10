#ifndef H_Clock
#define H_Clock

#include <SDL.h>
#include <SDL_main.h>

const float FPS_TARGET = 60.f;
const float DT_TARGET = 1.5f;

class Clock
{
public:
	static Clock* GetInstance();

	void Tick();
	float GetDeltaTime();
	

private:
	Clock();
	static Clock* m_Instance;

	float m_DeltaTime;
	float m_PreviousTime;
};

#endif