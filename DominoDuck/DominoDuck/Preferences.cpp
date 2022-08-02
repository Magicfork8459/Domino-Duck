#include "Preferences.h"

namespace dom
{
	Preferences::Preferences()
	{
		//TODO
		//? Default to %LOCALAPPDATA%/[ExecutableName]/Configuration?
	}

	Preferences::Preferences(std::string path, std::string fileName)
		: filePath(path + fileName)
	{
		if (not std::filesystem::exists(filePath))
		{
			//XXX For more general use, should sanitize the path
			std::filesystem::create_directories(path);
			//TODO create a preferences file with defaults in the newly created directory
		}

		setPath("test");
	}

	void Preferences::setFileName(std::string fileName)
	{
		filePath.replace_filename(fileName);
	}

	void Preferences::setPath(std::string path)
	{
		if (std::filesystem::exists(path))
		{
			std::string fileName = filePath.filename().string();

			filePath = path.append(fileName);
		}
	}
}