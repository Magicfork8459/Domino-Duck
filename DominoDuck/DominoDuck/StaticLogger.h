#pragma once
#include <filesystem>
#include <fstream>

#include <boost/format.hpp>
#include <boost/describe.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/common.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/from_stream.hpp>
#include <boost/log/utility/setup/formatter_parser.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/support/date_time.hpp>

namespace dom
{
	enum CharSeverity
	{
		//! Trace
		T,
		//! Debug
		D,
		//! Info
		I,
		//! Warning
		W,
		//! Error
		E
	};

	BOOST_DESCRIBE_ENUM(CharSeverity, T, D, I, W, E);

	template< typename CharT, typename TraitsT >
	inline std::basic_ostream< CharT, TraitsT >& operator<< (
		std::basic_ostream< CharT, TraitsT >& strm, CharSeverity lvl)
	{
		strm << boost::describe::enum_to_string(lvl, "");
		return strm;
	}

	class StaticLogger
	{
		using CharSeverityLogger = boost::log::sources::severity_logger<CharSeverity>;

	public:
		static void initialize();
		static void log(const CharSeverity& severity, const std::string& message);

	private:
		inline static bool hasBeenInitialized = false;
		inline static std::string filePath = "log.log";
	};
}