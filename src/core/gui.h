/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CORE_GUI_H
#define CORE_GUI_H

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <glfw/glfw3.h>
#include <string>

class gui
{
public:
    gui();
    ~gui();

private:
    /* Setup window */
    bool _setup_window();

    /* Window create state */
    bool _is_window_create = false;

    /* Set GLSL version */
    const char *glsl_version = "#version 130";
    void _set_glsl_version();

    /* Window */
    GLFWwindow *window = nullptr;

    /* imgui window color */
    ImVec4 _clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    /* Create window */
    bool _create_window();

    /* imgui initialization */
    void _imgui_init();

    /* Run window */
    void _run();

    /* Show main window */
    bool _show_main_window = true;

    /* States */
    bool _show_gui_window = true;

    /* render */
    void _render();

    /* Imgui test window */
    void _window_test();

    /* Imgui test window show */
    bool _window_test_show = true;

    /* Author */
    void _about();

    /* Authow window show */
    bool _show_about = true;

    /* main window */
    void _window_main();
};

#endif // CORE_GUI_H