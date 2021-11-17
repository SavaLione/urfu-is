/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#include "io/logger.h"

#include "core/settings.h"

void logger_init()
{
    settings &settings_instance = settings::Instance();

    switch (settings_instance.l_level())
    {
    case log_level::TRACE:
        spdlog::set_level(spdlog::level::trace);
        break;
    case log_level::DEBUG:
        spdlog::set_level(spdlog::level::debug);
        break;
    case log_level::INFO:
        spdlog::set_level(spdlog::level::info);
        break;
    case log_level::WARN:
        spdlog::set_level(spdlog::level::warn);
        break;
    case log_level::ERROR:
        spdlog::set_level(spdlog::level::err);
        break;
    case log_level::CRITICAL:
        spdlog::set_level(spdlog::level::critical);
        break;
    default:
        spdlog::set_level(spdlog::level::info);
        break;
    }

    // spdlog::set_pattern("[%H:%M:%S %z] [%^%L%$] [thread %t] %v");
}