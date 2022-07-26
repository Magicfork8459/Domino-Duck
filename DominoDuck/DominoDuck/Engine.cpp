#include "Engine.h"

//Render
	// Background
	//
//Scene flow
	// Opening credits
	// Title menu
	// Presumably a game based off the menu selection

namespace dom
{
	Engine::Engine()
		: isRunning(false)
	{
		if (SDL_Init(SDL_INIT_VIDEO) not_eq 0)
			SDL_Log(SDL_GetError());
		else
			gameWindow = std::make_unique<Window>("Domino Duck");
	}

	int Engine::run()
	{
		int exitCode = 0;

		if (gameWindow)
		{
			SDL_Event event;
			isRunning = true;

			while (isRunning)
			{
				while (SDL_PollEvent(&event) not_eq 0)
				{
					isRunning = event.type not_eq SDL_QUIT;
				}
			}
		}
		else
			exitCode = -1;

		return exitCode;
	}
}