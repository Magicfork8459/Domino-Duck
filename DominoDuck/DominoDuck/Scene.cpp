#include "Scene.h"

namespace dom
{
	Scene::Scene()
		: finished(false)
	{

	}
	bool Scene::hasFinished() const
	{
		return finished;
	}

	TimedStaticScene::TimedStaticScene()
		: Scene()
	{
	}

	bool TimedStaticScene::load()
	{
		// load associated assets to global

		auto e = EventSignaller::registerForEvent<EventSignaller::KeyboardEventSignal>(SDL_KEYUP, [](const SDL_KeyboardEvent& keyboardEvent)
			{
				switch (keyboardEvent.keysym.sym)
				{
				case SDL_KeyCode::SDLK_RETURN:
				case SDL_KeyCode::SDLK_SPACE:
					std::cout << "User has requested to skip scene" << std::endl;
					break;
				}
			});

		if(e.connected())
			connections.push_back(e);
		
		//! in this case we would want to return true if all the signals connected
		return true;
	}

	bool TimedStaticScene::unload()
	{
		for (auto& connection : connections)
		{
			connection.disconnect();
		}

		connections.clear();

		return false;
	}

	void TimedStaticScene::update(unsigned long long deltaTime)
	{
		std::cout << deltaTime << std::endl;
	}
}