#pragma once
#include <iostream>
#include <filesystem>
#include <string>

namespace dom
{
	class Preferences
	{
	public:
		Preferences();
		Preferences(std::string path, std::string fileName);
		
		void setFileName(std::string fileName);
		void setPath(std::string path);

	private:
		std::filesystem::path filePath;
	};
}