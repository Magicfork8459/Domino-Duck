#pragma once
//#include <fpieee.h>
#include <memory>
#include <regex>

#include "SDL.h"

#include "Window.h"
#include "GameClock.h"
#include "EventSignaller.h"
#include "Scene.h"

namespace dom
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		int run();
	private:
		bool isRunning;
		std::unique_ptr<Window> gameWindow;
		GameClock clock;
		//EventSignaller eventSignaller;
		// scene queue?
	};
}