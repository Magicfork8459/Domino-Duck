#pragma once

#include "SDL.h"

namespace dom
{
	class Texture
	{
	public:
		Texture();
		~Texture();
		SDL_Texture& underlying();
	private:
		SDL_Texture* texture;
	};
}