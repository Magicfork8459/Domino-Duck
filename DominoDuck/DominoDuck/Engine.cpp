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
			/*EventSignaller::registerForEvent<EventSignaller::KeyboardEventSignal>(SDL_KEYDOWN, [](const SDL_KeyboardEvent& keyboardEvent)
				{
					std::cout << "Key: " << keyboardEvent.keysym.sym << std::endl;
				});*/

			//TODO just testing here
			//assetManager.registerAssets();
			//Scene* s = new TimedStaticScene();
			sceneQueue.emplace(std::make_shared<TimedStaticScene>());

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
			TimedStaticScene scene;
			scene.load();

			EventSignaller::registerForEvent<EventSignaller::KeyboardEventSignal>(SDL_KEYUP, [&](const SDL_KeyboardEvent& keyboardEvent) 
				{
					if (keyboardEvent.keysym.sym == SDL_KeyCode::SDLK_u)
						scene.unload();
				});

			while (isRunning)
			{
				while (SDL_PollEvent(&event) not_eq 0)
				{
					isRunning = event.type not_eq SDL_QUIT;

					EventSignaller::processEvent(event);
				}

				if (not sceneQueue.front()->hasFinished())
				{
					sceneQueue.front()->update(clock.elapsed());
				}
				else
					sceneQueue.pop();

				clock.restart();
				gameWindow->render();
			}
		}
		else
			exitCode = -1;

		return exitCode;
	}
}