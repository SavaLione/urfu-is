#include "core/isl.h"
#include "gui/gui.h"
#include "core/settings.h"
#include "io/logger.h"

int main(int argc, char *argv[])
{
    /* Logger initialization */
    logger_init();

    /* Settings initialization */
    settings &settings_instance = settings::Instance();

    /* gui */
    gui g;

    return 0;
}