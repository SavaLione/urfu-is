/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef GUI_GUI_H
#define GUI_GUI_H

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <glfw/glfw3.h>
#include <string>

#include <cipher/additive.h>
#include <cipher/multiplicative.h>
#include <cipher/affine.h>
#include <cipher/autokey.h>
#include <cipher/playfair.h>
#include <cipher/vigenere.h>
//#include <cipher/hill.h>
#include <cipher/transposition.h>

class gui
{
public:
    gui();
    ~gui();

private:
    /* ImGui text widget (?) helper */
    static void _help_marker(const char* desc);

    /* Setup window */
    bool _setup_window();

    /* Window create state */
    bool _is_window_create = false;

    /* GLSL version */
    const char *glsl_version = "#version 130";

    /* Set GLSL version */
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

    /* Main window size */
    ImVec2 _main_window_size = ImVec2(168, 262);

    /* States */
    bool _show_gui_window = true;

    /* render */
    void _render();

    /* Imgui test window */
    void _window_test();

    /* Imgui test window show */
    bool _window_test_show = false;

    /* Author */
    void _about();

    /* Authow window show */
    bool _show_about = false;

    /* main window */
    void _window_main();

    /* Ciphers */
    bool _show_additive_cipher = false;
    bool _show_multiplicative_cipher = false;
    bool _show_affine_cipher = false;
    bool _show_autokey_cipher = false;
    bool _show_playfair_cipher = false;
    bool _show_vigenere_cipher = false;
    bool _show_hill_cipher = false;
    bool _show_transposition_cipher = false;

    void _close_all_cipher_windows();

    void additive_cipher();
    void multiplicative_cipher();
    void affine_cipher();
    void autokey_cipher();
    void playfair_cipher();
    void vigenere_cipher();
    void hill_cipher();
    void transposition_cipher();

    /* Additive */
    additive ad;
    ImVec2 _additive_window_size = ImVec2(606, 315);

    /* Multiplicative */
    multiplicative mp;

    /* Affine */
    affine af;
    ImVec2 _affine_window_size = ImVec2(606, 336);

    /* Autokey */
    autokey ak;

    /* Playfair */
    playfair pf;

    /* Vigenere */
    vigenere vr;

    /* Transposition */
    transposition tp;

    /* Choose alphabet */
    void _choose_alphabet();

    /* Alphabet */
    std::string _alphabet = "abcdefghijklmnopqrstuvwxyz";

    /* Key */
    std::string _key = "";

    /* Key a */
    std::string _key_a = "3";

    /* Key b */
    std::string _key_b = "5";

    /* Source text */
    std::string _source_text = "";

    /* Cipher text */
    std::string _cipher_text = "";
};

#endif // GUI_GUI_H