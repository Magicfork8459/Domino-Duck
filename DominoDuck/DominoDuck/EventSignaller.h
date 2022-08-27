#pragma once
#include <iostream>
#include <variant>
#include <boost/signals2/signal.hpp>
#include "SDL.h"

namespace dom
{	
	template<typename SignalArguments>
	class Event
	{
	public:
		
	private:
		boost::signals2::signal<void(SignalArguments)> signal;
	};

	class EventSignaller
	{
	public:
		
		using EventSignal = boost::signals2::signal<void(const SDL_Event&)>;
		using KeyboardEventSignal = boost::signals2::signal<void(const SDL_KeyboardEvent& keyboardEvent)>;
		using MouseButtonEventSignal = boost::signals2::signal<void(const SDL_MouseButtonEvent& mouseButtonEvent)>;
		using EventVariant = std::variant<KeyboardEventSignal, MouseButtonEventSignal>;
		
		static void processEvent(const SDL_Event& event);
		//void registerForEvent(Uint32 type, KeyboardEventSignal::slot_type slot);
		template <typename Signal, typename Slot = Signal::slot_type>
		static boost::signals2::connection registerForEvent(Uint32 type, Slot slot)
		{
			return std::get<Signal>(events[type]).connect(slot);
		}
	private:
		EventSignaller();
		static inline std::map<Uint32, EventVariant> events;
	};
}