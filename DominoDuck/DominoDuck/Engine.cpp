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
		{
			

			gameWindow = std::make_unique<Window>("Domino Duck");
		}
	}

	Engine::~Engine()
	{
		gameWindow.reset();
		SDL_Quit();
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
					if (isRunning = event.type not_eq SDL_QUIT)
						eventSignaller.processEvent(event);
				}

				// update scene with delta
				//std::cout << clock.elapsed() << std::endl;
				clock.restart();
				gameWindow->render();
			}
		}
		else
			exitCode = -1;

		return exitCode;
	}
}