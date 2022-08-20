#pragma once
#include <string>

#include <boost\describe.hpp>
#include "SDL.h"

#include "Preferences.hpp"
#include "GlobalLogger.h"

namespace dom
{
	//? Other potentially useful settings
	//- X/Y Position
	//- Display
	struct WindowSettings
	{
		void operator=(const WindowSettings& settings);

		bool fullscreen { true };
		bool borderless { false };
		int width { 0 };
		int height { 0 };
	};

	BOOST_DESCRIBE_STRUCT(WindowSettings, (), (fullscreen, borderless, width, height));

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