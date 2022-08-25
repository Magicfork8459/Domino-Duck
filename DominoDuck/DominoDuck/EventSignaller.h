#pragma once
#include <iostream>
#include <boost/signals2/signal.hpp>
#include "SDL.h"

namespace dom
{
	class EventSignaller
	{
	public:
		using EventSignal = boost::signals2::signal<void(const SDL_Event&)>;
		using KeyboardEventSignal = boost::signals2::signal<void(const SDL_KeyboardEvent& keyboardEvent)>;

		void processEvent(const SDL_Event& event);
		//void registerForEvent(Uint32 type, );
	private:
		//! See if we can use a multimap instead of doing this sort of thing
		KeyboardEventSignal keyPress;
		KeyboardEventSignal keyRelease;
	};
}