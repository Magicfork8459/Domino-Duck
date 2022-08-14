#include <regex>
#include "Engine.h"

std::filesystem::path getWorkingDirectory()
{
	std::string workingDirectory;
	size_t requiredSize;

	getenv_s(&requiredSize, NULL, 0, "LOCALAPPDATA");

	workingDirectory.resize(requiredSize);

	if (getenv_s(&requiredSize, &workingDirectory[0], requiredSize, "LOCALAPPDATA") == 0)
	{
		workingDirectory.pop_back();
		workingDirectory.append("\\DominoDuck");

		if (not std::filesystem::exists(workingDirectory))
		{
			try
			{
				std::filesystem::create_directories(workingDirectory);
			}
			catch (const std::filesystem::filesystem_error& exception)
			{
				std::cerr << exception.what() << std::endl;
			}
		}
	}
	else
		workingDirectory.clear();

	return workingDirectory;
}

int main(int argc, char** argv)
{
	GlobalLogger::settings.path = getWorkingDirectory().append("DD.log");
	GlobalLogger::initialize();

	dom::Engine engine;

	GLOBAL_LOG_DEBUG("Running engine...");
	return engine.run();
}
