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
	Window::Window(const std::string& title)
		: window(NULL)
	{
		SDL_Rect displayRect;
		if (SDL_GetDisplayUsableBounds(0, &displayRect) not_eq 0)
			SDL_Log(SDL_GetError());
		
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, displayRect.w, displayRect.h, SDL_WINDOW_SHOWN);
		
		if (window)
		{

		}
		else
			SDL_Log(SDL_GetError());
	}

	Window::~Window()
	{
		SDL_DestroyWindow(window);
	}
}