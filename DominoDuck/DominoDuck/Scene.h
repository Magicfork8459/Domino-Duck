#pragma once

#include "SDL.h"
#include "EventSignaller.h"

namespace dom
{
	class Scene
	{
	public:
		Scene();

		virtual void update(unsigned long long deltaTime) = 0;
		bool hasFinished() const;

	protected:
		virtual bool load() = 0;
		virtual bool unload() = 0;
		

		std::list<boost::signals2::connection> connections;
		bool finished;
	};

	class TimedStaticScene : public virtual Scene
	{
	public:
		TimedStaticScene();
		bool load() override;
		bool unload() override;
		void update(unsigned long long deltaTime) override;
	};
}