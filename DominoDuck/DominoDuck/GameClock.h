#pragma once

#include "SDL.h"

namespace dom
{
	class GameClock
	{
	public:
		GameClock();

		void start();
		void restart();
		void stop();
		void pause();
		unsigned long long elapsed();
	private:
		unsigned long long startTime;
		unsigned long long pauseTime;
		bool active;
	};
}