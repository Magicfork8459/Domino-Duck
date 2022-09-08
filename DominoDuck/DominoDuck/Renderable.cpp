#include "Renderable.h"

namespace dom
{
	Renderable::Renderable()
		: rect({0, 0, 0, 0})
	{

	}

	bool Renderable::render(SDL_Renderer& renderer)
	{
		bool rendered = texture.get();

		if (rendered)
		{
			// TODO handle clips for sprites, angle, center and flip
			if (not (rendered = SDL_RenderCopyEx(&renderer, &texture->underlying(), NULL, &rect, 0.0, NULL, SDL_FLIP_NONE) == 0))
			{
				GLOBAL_LOG_ERROR(SDL_GetError());
			}
		}

		return rendered;
	}
}