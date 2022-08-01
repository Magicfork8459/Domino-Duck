#include "Preferences.h"

namespace dom
{
	Preferences::Preferences()
	{
		//TODO
		//? Default to %LOCALAPPDATA%/[ExecutableName]/Configuration?
	}

	Preferences::Preferences(std::string path, std::string fileName)
		: fileName(fileName)
		, path(path)
	{
		fileExists();
	}

	bool Preferences::fileExists()
	{
		//XXX seems to append in place, so have to do this differently
		std::filesystem::path pathToPreferences = path.append(fileName);
		//TODO check %LOCALAPPDATA%/DominoDuck/Configuration
		if (std::filesystem::exists(pathToPreferences))
			std::cout << "Hey!" << std::endl;

		return false;
	}
}