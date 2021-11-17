/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CORE_SETTINGS_H
#define CORE_SETTINGS_H

#include <string>

enum log_level
{
    TRACE = 1,
    DEBUG = 2,
    INFO = 3,
    WARN = 4,
    ERROR = 5,
    CRITICAL = 6
};

class settings
{
public:
    static settings &Instance()
    {
        static settings s;
        return s;
    }

    ~settings();

    /* Уровень логирования */
    log_level l_level();

private:
    settings();
    settings(settings const &) = delete;
    settings &operator=(settings const &) = delete;

    /* Уровень логирования */
    log_level _l_level = log_level::INFO;
};

#endif // CORE_SETTINGS_H