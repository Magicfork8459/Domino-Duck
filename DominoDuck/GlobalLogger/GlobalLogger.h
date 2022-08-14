#pragma once
#include <filesystem>

#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes/mutable_constant.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>

BOOST_LOG_GLOBAL_LOGGER(globalLogger, boost::log::sources::severity_channel_logger_mt<boost::log::trivial::severity_level>);

template<typename T>
void setAttribute(const char* name, const T& value)
{
	return boost::log::attribute_cast<boost::log::attributes::mutable_constant<T>>(boost::log::core::get()->get_thread_attributes()[name]).set(value);
}

static inline std::string stripFilePath(const std::string& path)
{
	return std::filesystem::path(path).filename().string();
}

class GlobalLogger
{
public:
	static void initialize();

	struct Settings
	{
		std::filesystem::path path;
	};

	static inline Settings settings;

private:
	static inline bool hasBeenInitialized = false;
};

//XXX Is only logging on program exit, need to fix that
#define LOG_LOG_LOCATION(LOGGER, LEVEL, MSG) \
	setAttribute<std::string>("File", stripFilePath(__FILE__)); \
	setAttribute<int>("Line", __LINE__); \
	BOOST_LOG_SEV(LOGGER, boost::log::trivial::LEVEL) << MSG

#define GLOBAL_LOG_TRACE(MESSAGE)	LOG_LOG_LOCATION(globalLogger::get(), trace,		MESSAGE);
#define GLOBAL_LOG_DEBUG(MESSAGE)	LOG_LOG_LOCATION(globalLogger::get(), debug,		MESSAGE);
#define GLOBAL_LOG_INFO(MESSAGE)	LOG_LOG_LOCATION(globalLogger::get(), info,			MESSAGE);
#define GLOBAL_LOG_WARN(MESSAGE)	LOG_LOG_LOCATION(globalLogger::get(), warning,		MESSAGE);
#define GLOBAL_LOG_ERROR(MESSAGE)	LOG_LOG_LOCATION(globalLogger::get(), error,		MESSAGE);
#define GLOBAL_LOG_FATAL(MESSAGE)	LOG_LOG_LOCATION(globalLogger::get(), fatal,		MESSAGE);

