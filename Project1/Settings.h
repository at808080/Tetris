#ifndef H_SETTINGS
#define H_SETTINGS

#include <stdint.h>

class Settings
{
public:
	Settings();
	Settings(int input_time_, int gravity_time_);
	int GetInputTime();
	void SetInputTime(int t_);
	int GetGravityTime();
	void SetGravityTime(int t_);

private:
	int m_InputTime;
	int m_GravityTime;

};

#endif