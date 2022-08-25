#include "EventSignaller.h"

namespace dom
{
	void EventSignaller::processEvent(const SDL_Event& event)
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			keyPress(event.key);
			break;
		case SDL_KEYUP:
			keyRelease(event.key);
			break;
		}
	}
}