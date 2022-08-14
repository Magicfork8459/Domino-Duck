#include "GlobalLogger.h"

BOOST_LOG_GLOBAL_LOGGER_CTOR_ARGS(globalLogger,
    boost::log::sources::severity_channel_logger_mt<boost::log::trivial::severity_level>,
    (boost::log::keywords::channel = "GLF"));

void GlobalLogger::initialize()
{
    settings.path.make_preferred();

    auto tempPath = settings.path;
    bool directoryExists = std::filesystem::exists(tempPath.remove_filename());

    if (directoryExists and not hasBeenInitialized)
    {
        boost::log::add_common_attributes();
        boost::log::core::get()->add_thread_attribute("File", boost::log::attributes::mutable_constant<std::string>("UNKNOWN_FILE"));
        boost::log::core::get()->add_thread_attribute("Line", boost::log::attributes::mutable_constant<int>(0));

        boost::log::add_console_log(std::clog, boost::log::keywords::format = "%TimeStamp%: %Message%");
        boost::log::add_file_log
        (settings.path
#ifdef _DEBUG
            , boost::log::keywords::filter = boost::log::expressions::attr<boost::log::trivial::severity_level>("Severity") > boost::log::trivial::severity_level::trace
#elif NDEBUG
            , boost::log::keywords::filter = boost::log::expressions::attr<boost::log::trivial::severity_level>("Severity") > boost::log::trivial::severity_level::debug
#endif
            , boost::log::keywords::format = boost::log::expressions::stream
            << '<' << boost::log::expressions::attr<boost::log::trivial::severity_level>("Severity") << "> "
            << '[' << boost::log::expressions::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d*%H:%M:%S")
            << " (" << boost::log::expressions::attr<std::string>("File") << ':' << boost::log::expressions::attr<int>("Line") << ")]"
            << ": " << boost::log::expressions::smessage
        );

        hasBeenInitialized = directoryExists;
    }
}