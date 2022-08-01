#pragma once
//#include <fpieee.h>
#include <memory>

#include "SDL.h"

#include "Preferences.h"
#include "Window.h"

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
		std::unique_ptr<Preferences> preferences;
	};
}