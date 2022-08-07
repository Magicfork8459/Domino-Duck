#pragma once
#include <iostream>
#include <filesystem>
#include <string>

#include <boost\describe.hpp>
#include <boost\mp11.hpp>
#include <boost\json.hpp>

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

        void setSettings(Settings settings)
        {
            this->settings = settings;
        }

    private:
        Settings settings;
        std::filesystem::path filePath;
    };
}