#include "Scene.h"

namespace dom
{
	TestScene::TestScene()
		: Scene()
	{
	}

	bool TestScene::load()
	{
		
		auto e = EventSignaller::registerForEvent<EventSignaller::KeyboardEventSignal>(SDL_KEYUP, [](const SDL_KeyboardEvent& keyboardEvent)
			{
				//! Put this stuff in a load
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

	bool TestScene::unload()
	{
		for (auto& connection : connections)
		{
			connection.disconnect();
		}

		connections.clear();

		return false;
	}
}