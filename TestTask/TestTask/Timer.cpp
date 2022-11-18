#include "Timer.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

float Timer::StartTimer()
{
	return std::chrono::high_resolution_clock::now();
}
