#pragma once
#include <string>

#include <boost\describe.hpp>
#include "SDL.h"

#include "Preferences.hpp"
#include "GlobalLogger.h"

namespace dom
{
	struct WindowSettings
	{
		const int DEFAULT_HEIGHT = 768;
		const int DEFAULT_WIDTH = 1366;

		void operator=(const WindowSettings& settings);

		bool fullscreen { false };
		bool borderless { false };
		int display { 0 };
		int width { DEFAULT_WIDTH };
		int height { DEFAULT_HEIGHT };
		//? x/y position?

		//BOOST_DESCRIBE_CLASS(WindowSettings, (), (), (), (fullscreen, borderless, display, width, height))
		
	};

	BOOST_DESCRIBE_STRUCT(WindowSettings, (), (fullscreen, borderless, display, width, height));

	class Window
	{
	public:
		Window(const std::string& title);
		~Window();

		void render();
		//const SDL_Renderer* getRenderer();

	private:
		void applySettings();

		SDL_Window* window;
		SDL_Renderer* renderer;
		Preferences<WindowSettings> preferences;
	};
}