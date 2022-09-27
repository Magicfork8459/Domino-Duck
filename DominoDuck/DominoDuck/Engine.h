#pragma once

#include <memory>
#include <queue>
#include <regex>

#include "SDL.h"

#include "Window.h"
#include "GameClock.h"
#include "EventSignaller.h"
#include "Scene.h"
#include "AssetManager.h"

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
		std::queue<std::shared_ptr<Scene>> sceneQueue;

	};
}