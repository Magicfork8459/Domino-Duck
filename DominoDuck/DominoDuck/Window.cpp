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
	/*WindowSettings::WindowSettings()
		: fullscreen(true)
		, borderless(true)
		, display(0)
	{

	}*/

	/*const bool& WindowSettings::isFullscreen()
	{
		return fullscreen;
	}*/

	//void WindowSettings::setFullscreen(const bool& fullscreen)
	//{
	//	this->fullscreen = fullscreen;

	//	//TODO emit signal to window so it can update
	//}

	void WindowSettings::operator=(const WindowSettings& settings)
	{
		this->fullscreen = settings.fullscreen;
		this->borderless = settings.borderless;
		this->width = settings.width;
		this->height = settings.height;
	}

	Window::Window(const std::string& title)
		: window(NULL)
	{
		int windowFlags = SDL_WINDOW_SHOWN;

		preferences.setDirectory("WindowSettings");
		
		if (preferences.load())
		{
			GLOBAL_LOG_DEBUG("loaded previous settings");
		}

		WindowSettings settings = preferences.getSettings();
		
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, settings.width, settings.height, windowFlags);
		
		if (not window)
		{
			GLOBAL_LOG_ERROR(SDL_GetError());
			throw "Window failed to initialize";
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			applySettings();
		}
	}

	Window::~Window()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}

	void Window::render()
	{
		// Just want a blank screen for testing our window stuff for now
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	void Window::applySettings()
	{
		auto settings = preferences.getSettings();
		int fullscreenFlag = settings.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;

		if (not settings.fullscreen)
		{
			SDL_SetWindowSize(window, settings.height, settings.width);
		}

		SDL_SetWindowBordered(window, settings.borderless ? SDL_FALSE : SDL_TRUE);
		SDL_SetWindowFullscreen(window, fullscreenFlag);
	}
}