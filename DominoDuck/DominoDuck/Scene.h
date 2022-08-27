#pragma once

#include "SDL.h"
#include "EventSignaller.h"

namespace dom
{
	class Scene
	{
	public:
		//virtual void update(delta) = 0;
	protected:
		virtual bool load() = 0;
		virtual bool unload() = 0;

		std::list<boost::signals2::connection> connections;
	private:
		//
	};

	class TestScene : virtual Scene
	{
	public:
		TestScene();
		bool load() override;
		bool unload() override;
	};
}