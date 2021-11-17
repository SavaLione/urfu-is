#include "core/gui_main.h"
#include "core/gui.h"
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