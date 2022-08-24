#include "GameClock.h"

namespace dom
{
	GameClock::GameClock()
		: startTime(0)
		, pauseTime(0)
		, active(false)
	{

	}

	void GameClock::start()
	{
		if (!active)
		{
			startTime = SDL_GetTicks64();
			active = true;
		}
	}

	void GameClock::restart()
	{
		active = true;
		startTime = SDL_GetTicks64();
		pauseTime = 0;
	}

	void GameClock::stop()
	{
		active = false;
		startTime = 0;
		pauseTime = 0;
	}

	void GameClock::pause()
	{
		active = false;
		pauseTime = SDL_GetTicks64();
	}

	unsigned long long GameClock::elapsed()
	{
		return active ? (SDL_GetTicks64() - startTime) : pauseTime;
	}
}