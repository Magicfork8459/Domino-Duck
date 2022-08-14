#pragma once
#include <string>

#include <boost\describe.hpp>
#include "SDL.h"

#include "Preferences.hpp"
#include "GlobalLogger.h"

namespace dom
{
	class WindowSettings
	{
	public:
		WindowSettings();

		void setFullscreen(const bool& fullscreen);

	private:
		bool fullscreen;
		bool borderless;
		int display;
		int width;
		int height;
		//? x/y position?

		BOOST_DESCRIBE_CLASS(WindowSettings, (), (), (), (fullscreen, borderless, display, width, height))
	};

	class Window
	{
	public:
		Window(const std::string& title);
		~Window();
	private:
		SDL_Window* window;
		Preferences<WindowSettings> preferences;
	};
}