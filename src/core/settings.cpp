/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#include "core/settings.h"

#include "io/logger.h"

settings::settings()
{
}

settings::~settings()
{
}

log_level settings::l_level()
{
	return _l_level;
}