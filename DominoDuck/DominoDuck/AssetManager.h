#pragma once
#include <string>
#include <map>
#include <memory>
#include <filesystem>
#include "Renderable.h"

namespace dom
{
	class AssetManager
	{
	public:
		//! Parse a resource file?
	private:
		std::map<std::string, std::shared_ptr<Renderable>> loaded;
		std::map<std::string, std::filesystem::path> unloaded;
	};

	//? Make the functions in the class static instead?
	static inline AssetManager assetManager;
}