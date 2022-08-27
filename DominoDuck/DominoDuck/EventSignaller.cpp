#include "EventSignaller.h"

namespace dom
{
	//EventSignaller::EventSignaller()
	//	//: events({ { SDL_KEYUP, }})
	//{
	//	//events.insert({ SDL_KEYUP, KeyboardEventSignal()});
	//}

	void EventSignaller::processEvent(const SDL_Event& event)
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			std::get< KeyboardEventSignal>(events[event.type])(event.key);
			break;
		case SDL_MOUSEBUTTONDOWN:
			//event.b
			break;
		}

		//std::get<KeyboardEventSignal>(events[1]).connect([]() {});
	}

	/*void EventSignaller::registerForEvent(Uint32 type, KeyboardEventSignal::slot_type slot)
	{
		std::get<KeyboardEventSignal>(events[type]).connect(slot);
	}*/

}