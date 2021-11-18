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

#include "core/additive.h"
#include "core/multiplicative.h"
#include "core/affine.h"
#include "core/autokey.h"
#include "core/playfair.h"
#include "core/vigenere.h"
//#include "core/hill.h"
#include "core/transposition.h"

class gui
{
public:
    gui();
    ~gui();

private:
    static void _help_marker(const char* desc);

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
    std::string _autokey_key;

    /* Playfair */
    playfair pf;
    // std::string _playfair_key = "";
    // std::string _playfair_source_text = "";
    // std::string _playfair_cipher_text = "";

    /* Vigenere */
    vigenere vr;
    //std::string _vigenere_alphabet = "";
    // std::string _vigenere_key = "";
    // std::string _vigenere_source_text = "";
    // std::string _vigenere_cipher_text = "";

    /* Transposition */
    transposition tp;
    // std::string _transposition_key = "";
    // std::string _transposition_source_text = "";
    // std::string _transposition_cipher_text = "";

    /* other */

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

#endif // CORE_GUI_H