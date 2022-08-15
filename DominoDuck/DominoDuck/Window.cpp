#include "Window.h"

// Preferences
	// Video
		// Select Display
		// Window Mode
			// Fullscreen
			// Borderless
			// Windowed
				// Resolution

namespace dom
{
	WindowSettings::WindowSettings()
		: fullscreen(true)
		, borderless(true)
		, display(0)
	{

	}

	void WindowSettings::setFullscreen(const bool& fullscreen)
	{
		this->fullscreen = fullscreen;

		//TODO emit signal to window so it can update
	}

	Window::Window(const std::string& title)
		: window(NULL)
	{
		preferences.setDirectory("WindowSettings");
		// try a load
		if (preferences.load())
		{
			GLOBAL_LOG_DEBUG("loaded previous settings");
		}
		// otherwise use defaults
			// save defaults

		SDL_Rect displayRect;
		if (SDL_GetDisplayUsableBounds(0, &displayRect) not_eq 0)
			SDL_Log(SDL_GetError());
		
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, displayRect.w, displayRect.h, SDL_WINDOW_SHOWN);
		
		if (not window) 
		{ 
			GLOBAL_LOG_ERROR(SDL_GetError()); 
		}
	}

	Window::~Window()
	{
		SDL_DestroyWindow(window);
	}
}