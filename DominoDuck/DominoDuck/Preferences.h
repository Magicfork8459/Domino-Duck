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
		
	private:
		bool fileExists();

		std::string fileName;
		std::filesystem::path path;
	};
}