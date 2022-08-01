#pragma once
#include <string>

#include "SDL.h"

namespace dom
{
	class Window
	{
	public:
		Window(const std::string& title);
		~Window();
	private:
		SDL_Window* window;
	};
}