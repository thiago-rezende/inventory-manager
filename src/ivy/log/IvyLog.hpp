#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace ivy
{
/**
 * @brief Classe IvyLog
 * Responsavel por disponibilizar funcoes de log
 */
class IvyLog
{
private:
    /**
     * @brief logger
     * 
     */
    static std::shared_ptr<spdlog::logger> s_ivyLogger;

public:
    /**
     * @brief Inicializa o IvyLogger
     * 
     */
    static void init();

    /**
     * @brief Retorna o logger
     * 
     * @return std::shared_ptr<spdlog::logger>& logger
     */
    inline static std::shared_ptr<spdlog::logger> &getLogger() { return s_ivyLogger; }
};
} // namespace ivy

#ifdef IVY_DEBUG
#define IVY_TRACE(...) ::ivy::IvyLog::getLogger()->trace(__VA_ARGS__)
#define IVY_INFO(...) ::ivy::IvyLog::getLogger()->info(__VA_ARGS__)
#define IVY_WARN(...) ::ivy::IvyLog::getLogger()->warn(__VA_ARGS__)
#define IVY_ERROR(...) ::ivy::IvyLog::getLogger()->error(__VA_ARGS__)
#define IVY_CRITICAL(...) ::ivy::IvyLog::getLogger()->critical(__VA_ARGS__)
#else
#define IVY_TRACE(...)
#define IVY_INFO(...)
#define IVY_WARN(...)
#define IVY_ERROR(...)
#define IVY_CRITICAL(...)
#endif
