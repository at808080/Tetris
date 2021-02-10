#include "Clock.h"


Clock* Clock::m_Instance = nullptr;

Clock* Clock::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new Clock();
	}
	return m_Instance;
}

void Clock::Tick()
{
	m_DeltaTime = (SDL_GetTicks() - m_PreviousTime) * (FPS_TARGET / 1000.f);

	if (m_DeltaTime > DT_TARGET)
	{
		m_DeltaTime = DT_TARGET;
	}

	m_PreviousTime = SDL_GetTicks();
}

float Clock::GetDeltaTime()
{
	return m_DeltaTime;
}

Clock::Clock()
	: m_DeltaTime(DT_TARGET), m_PreviousTime(DT_TARGET)
{
}
