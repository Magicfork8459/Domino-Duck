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
			size_t requiredSize;
			std::string pathToAppData;

			//XXX BEGIN Windows specific
			getenv_s(&requiredSize, NULL, 0, "LOCALAPPDATA");

			pathToAppData.resize(requiredSize);

			if (getenv_s(&requiredSize, &pathToAppData[0], requiredSize, "LOCALAPPDATA") == 0)
			{ 
				//! Truncate null terminators so the path construction works
				pathToAppData.erase(pathToAppData.begin() + pathToAppData.find_first_of('\0'), pathToAppData.end());
				preferences = std::make_unique<Preferences>(pathToAppData.append("\\DominoDuck\\Configuration\\"), "Preferences.json");
			}
			else
				SDL_LogDebug(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "Couldn't create handle to preferences file, will use defaults");
			//XXX END Windows specific

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
					isRunning = event.type not_eq SDL_QUIT;

					// pass event to current scene
				}

				// update scene with delta
			}
		}
		else
			exitCode = -1;

		return exitCode;
	}
}