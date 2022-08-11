#include "StaticLogger.h"
#include "Engine.h"

int main(int argc, char** argv)
{
	dom::StaticLogger::initialize();
	dom::Engine engine;

	return engine.run();
}
