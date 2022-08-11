#include "StaticLogger.h"

namespace dom
{
    void StaticLogger::initialize()
    {
        if (not hasBeenInitialized)
        {
            boost::log::add_console_log(std::clog, boost::log::keywords::format = "%TimeStamp%: %Message%");
            boost::log::add_file_log
            (     filePath
                , boost::log::keywords::filter = boost::log::expressions::attr<CharSeverity>("Severity") > CharSeverity::D
                , boost::log::keywords::format = boost::log::expressions::stream
                << '[' << boost::log::expressions::attr<CharSeverity>("Severity") << "] "
                << '[' << boost::log::expressions::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d*%H:%M:%S")
                << " ( " << boost::log::expressions::format_named_scope("Scope", boost::log::keywords::format = "%F:%l") << ")]"
                << ": " << boost::log::expressions::message
            );
            boost::log::add_common_attributes();
            boost::log::core::get()->add_global_attribute("Scope", boost::log::attributes::named_scope());

            hasBeenInitialized = true;
        }
    }

    void StaticLogger::log(const CharSeverity& severity, const std::string& message)
    {
        if (hasBeenInitialized)
        {
            CharSeverityLogger logger;

            BOOST_LOG_SEV(logger, severity) << message;
        }
    }
}