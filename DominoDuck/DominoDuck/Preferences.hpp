#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include <boost\describe.hpp>
#include <boost\mp11.hpp>
#include <boost\json.hpp>
#include <boost\format.hpp>

#include "GlobalLogger.h"

namespace dom
{
	template
		<
		class Settings
		, class Description = boost::describe::describe_members<Settings, boost::describe::mod_any_access>
		>
		inline static void tag_invoke(const boost::json::value_from_tag&, boost::json::value& v, const Settings& settings)
	{
		auto& obj = v.emplace_object();

		boost::mp11::mp_for_each<Description>
			([&](const auto& description)
				{
					obj[description.name] = boost::json::value_from(settings.*description.pointer);
				});
	}

	//! Template function pass through to get the type for the json::value_to template function
	template<typename Value>
	inline static void getValueFromJson(const boost::json::object& object, const std::string& name, Value& value)
	{
		value = boost::json::value_to<Value>(object.at(name));
	}

	template
		<
		class Settings
		, class Description = boost::describe::describe_members<Settings, boost::describe::mod_any_access>
		>
		inline static Settings tag_invoke(const boost::json::value_to_tag<Settings>&, const boost::json::value& value)
	{
		auto& object = value.as_object();
		Settings settings;

		boost::mp11::mp_for_each<Description>([&](const auto& description)
			{
				getValueFromJson(object, description.name, settings.*description.pointer);
			});

		return settings;
	}

    template
        <
        class Settings
        , class Members = boost::describe::describe_members<Settings, boost::describe::mod_any_access>
        >
        class Preferences
    {
		const std::string FILENAME = "preferences.json";
    public:

        Preferences()
        {

        }

        Preferences(Settings settings)
            : settings(settings)
        {

        }

        Preferences(const boost::json::value& json)
            : settings(fromJson(json))
        {
        }

        std::string toJsonString()
        {
            std::stringstream ss;
            ss << boost::json::value_from(settings);

            return ss.str();
        }

        boost::json::value toJson()
        {
            return boost::json::value_from(settings);
        }

        static Settings fromJson(const boost::json::value& value)
        {
            return boost::json::value_to<Settings>(value);
        }

		bool load()
		{
			std::filesystem::path pathToPreferences = directory.append(FILENAME);
			bool succeeded = std::filesystem::exists(pathToPreferences);

			if (succeeded)
			{
				std::ifstream file(pathToPreferences, std::ios::beg);
				succeeded = file.good();

				if (succeeded)
				{
					size_t fileSize = file.tellg();
					std::string jsonString(fileSize, '\0');
					file.read(&jsonString[0], fileSize);
					file.close();

					try
					{
						this->settings = fromJson(boost::json::parse(jsonString));
					}
					//XXX Can throw on json parse, need to get specific exception
					catch (const std::exception& exception)
					{
						GLOBAL_LOG_ERROR(exception.what());
					}
				}
			}

			

			return succeeded;
		}

        void setDirectory(const std::string& directory)
        {
			std::filesystem::path pathToFile = GlobalLogger::settings.path;
			{
				pathToFile.remove_filename();
				pathToFile += (directory);
				pathToFile.make_preferred();
			}
			bool succeeded = std::filesystem::exists(pathToFile);

			if (not succeeded)
			{
				try
				{
					succeeded = std::filesystem::create_directories(pathToFile);
				}
				catch (const std::filesystem::filesystem_error& exception)
				{
					GLOBAL_LOG_ERROR(exception.what());
				}
			}

			if (succeeded)
			{
				this->directory = pathToFile;
			}
        }

        void setSettings(Settings settings)
        {
            this->settings = settings;
        }

    private:
        Settings settings;
        std::filesystem::path directory;
    };
}