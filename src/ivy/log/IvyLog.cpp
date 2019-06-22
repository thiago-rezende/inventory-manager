#include "IvyLog.hpp"

namespace ivy
{
std::shared_ptr<spdlog::logger> IvyLog::s_ivyLogger;

void IvyLog::init()
{
    spdlog::set_pattern("%^[%n][%l]: %v.%$");
    s_ivyLogger = spdlog::stdout_color_mt("IVY_LOG");
    s_ivyLogger->set_level(spdlog::level::trace);
}
} // namespace ivy
