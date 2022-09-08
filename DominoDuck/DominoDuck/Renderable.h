#include <list>
#include <queue>
#include <memory>

#include "SDL.h"

#include "Texture.h"
#include "GlobalLogger.h"

namespace dom
{
	class Renderable
	{
	public:
		bool render(SDL_Renderer& renderer);
	protected:
		Renderable();
	private:
		SDL_Rect rect;
		std::list<SDL_Rect> clips;
		std::unique_ptr<Texture> texture;
	};

	static inline std::queue<Renderable> renderingQueue;
}