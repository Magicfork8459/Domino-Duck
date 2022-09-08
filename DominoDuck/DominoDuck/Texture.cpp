#include "Texture.h"

namespace dom
{
	Texture::Texture()
		: texture(NULL)
	{


	}

	Texture::~Texture()
	{
		SDL_DestroyTexture(texture);
	}

	SDL_Texture& Texture::underlying()
	{
		return *texture;
	}
}
