#include "Settings.h"
Settings::Settings()
    : m_InputTime(0), m_GravityTime(0)
{

}
Settings::Settings(int input_time_, int gravity_time_)
    : m_InputTime(input_time_), m_GravityTime(gravity_time_)
{
}

int Settings::GetInputTime()
{
    return m_InputTime;
}

void Settings::SetInputTime(int t_)
{
    m_InputTime = t_;
}

int Settings::GetGravityTime()
{
    return m_GravityTime;
}

void Settings::SetGravityTime(int t_)
{
    m_GravityTime = t_;
}


