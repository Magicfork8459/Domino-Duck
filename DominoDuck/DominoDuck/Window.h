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
		const int DEFAULT_HEIGHT = 768;
		const int DEFAULT_WIDTH = 1366;

	public:
		WindowSettings();

		void setFullscreen(const bool& fullscreen);

	private:
		bool fullscreen { false };
		bool borderless { false };
		int display { 0 };
		int width { DEFAULT_WIDTH };
		int height { DEFAULT_HEIGHT };
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