#include "core/gui.h"
#include "core/compiler_version.h"
#include "io/logger.h"

#include "imgui/imgui_stdlib.h"

#include <stdexcept>

static void glfw_error_callback(int error, const char *description)
{
    spdlog::error("Glfw Error {}: {}", error, description);
}

void gui::_help_marker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

gui::gui()
{
    spdlog::info("Creating gui window.");

    if (_setup_window())
    {
        _set_glsl_version();
        if (_create_window())
        {
            _imgui_init();
            _run();
        }
    }
}

gui::~gui()
{
    spdlog::info("Exit from the gui window.");

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    if (_is_window_create)
    {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

bool gui::_setup_window()
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
    {
        spdlog::error("Glfw init error.");
        return false;
    }
    return true;
}

void gui::_set_glsl_version()
{
    // GL 3.0 + GLSL 130
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
}

bool gui::_create_window()
{
    window = glfwCreateWindow(720, 360, "Information security labs", NULL, NULL);
    if (window == NULL)
    {
        spdlog::error("GLFW window create error.");
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    _is_window_create = true;
    return true;
}

void gui::_imgui_init()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void gui::_window_test()
{
    if (_window_test_show)
    {
        ImGui::ShowDemoWindow();
    }
}

void gui::_run()
{
    while (_show_main_window)
    {
        _show_main_window = !glfwWindowShouldClose(window);

        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Imgui test window
        _window_test();

        // Main window
        _window_main();

        // About window
        _about();

        // Ciphers
        additive_cipher();
        multiplicative_cipher();
        affine_cipher();
        autokey_cipher();
        playfair_cipher();
        vigenere_cipher();
        hill_cipher();
        transposition_cipher();

        // render
        _render();
    }
}

void gui::_render()
{
    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(_clear_color.x * _clear_color.w, _clear_color.y * _clear_color.w, _clear_color.z * _clear_color.w, _clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
}

void gui::_about()
{
    if (_show_about)
    {
        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_NoResize;
        window_flags |= ImGuiWindowFlags_NoCollapse;

        ImGui::Begin("About", &_show_about, window_flags);

        ImGui::Text("Author: Savely Pototsky (SavaLione)");
        ImGui::Text("Group:  FOM-110510");
        ImGui::Text("Date:   2021-09-16");
        ImGui::Separator();
        ImGui::Text("c++ version: ");
        ImGui::SameLine();
        std::string _cpp_version = std::to_string(__cplusplus);
        ImGui::Text(_cpp_version.c_str());
        ImGui::Text("Compiler: ");
        ImGui::SameLine();
        ImGui::Text(compiler_version().c_str());
        ImGui::Text("Compile date: ");
        ImGui::SameLine();
        std::string _date = __DATE__;
        _date += " ";
        _date += __TIME__;
        ImGui::Text(_date.c_str());
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

        ImGui::End(); // About
    }
}

void gui::_window_main()
{
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoScrollbar;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoResize;
    window_flags |= ImGuiWindowFlags_NoCollapse;

    ImGui::SetNextWindowPos(ImVec2(0, 0));

    ImGui::Begin("Select cipher", &_show_main_window, window_flags);

    ImGui::SetWindowSize(_main_window_size);

    // if (true)
    // {
    //     ImVec2 size = ImGui::GetWindowSize();
    //     spdlog::info("size x={} y={}", size.x, size.y);
    // }

    ImGui::Text("Ciphers");
    ImGui::Separator();

    std::string str_additive        = "(1) Additive      ";
    std::string str_multiplicative  = "(2) Multiplicative";
    std::string str_affine          = "(3) Affine        ";
    std::string str_autokey         = "(4) Autokey       ";
    std::string str_playfair        = "(5) Playfair      ";
    std::string str_vigenere        = "(6) Vigenere      ";
    std::string str_hill            = "(7) Hill          ";
    std::string str_transposition   = "(8) Transposition ";
    std::string str_about           = "About                ";

    std::string str_spaces = "   ";
    std::string str_choice = "-> ";

    if(_show_additive_cipher)
    {
        str_additive.insert(0, str_choice);
    }
    else
    {
        str_additive.insert(0, str_spaces);
    }

    if(_show_multiplicative_cipher)
    {
        str_multiplicative.insert(0, str_choice);
    }
    else
    {
        str_multiplicative.insert(0, str_spaces);
    }

    if(_show_affine_cipher)
    {
        str_affine.insert(0, str_choice);
    }
    else
    {
        str_affine.insert(0, str_spaces);
    }

    if(_show_autokey_cipher)
    {
        str_autokey.insert(0, str_choice);
    }
    else
    {
        str_autokey.insert(0, str_spaces);
    }

    if(_show_playfair_cipher)
    {
        str_playfair.insert(0, str_choice);
    }
    else
    {
        str_playfair.insert(0, str_spaces);
    }

    if(_show_vigenere_cipher)
    {
        str_vigenere.insert(0, str_choice);
    }
    else
    {
        str_vigenere.insert(0, str_spaces);
    }

    if(_show_hill_cipher)
    {
        str_hill.insert(0, str_choice);
    }
    else
    {
        str_hill.insert(0, str_spaces);
    }

    if(_show_transposition_cipher)
    {
        str_transposition.insert(0, str_choice);
    }
    else
    {
        str_transposition.insert(0, str_spaces);
    }

    if (ImGui::Button(str_additive.c_str()))
    {
        _close_all_cipher_windows();
        _show_additive_cipher = true;
    }
    if (ImGui::Button(str_multiplicative.c_str()))
    {
        _close_all_cipher_windows();
        _show_multiplicative_cipher = true;
    }
    if (ImGui::Button(str_affine.c_str()))
    {
        _close_all_cipher_windows();
        _show_affine_cipher = true;
    }
    if (ImGui::Button(str_autokey.c_str()))
    {
        _close_all_cipher_windows();
        _show_autokey_cipher = true;
    }
    if (ImGui::Button(str_playfair.c_str()))
    {
        _close_all_cipher_windows();
        _show_playfair_cipher = true;
    }
    if (ImGui::Button(str_vigenere.c_str()))
    {
        _close_all_cipher_windows();
        _show_vigenere_cipher = true;
    }
    if (ImGui::Button(str_hill.c_str()))
    {
        _close_all_cipher_windows();
        _show_hill_cipher = true;
    }
    if (ImGui::Button(str_transposition.c_str()))
    {
        _close_all_cipher_windows();
        _show_transposition_cipher = true;
    }

    ImGui::Separator();
    if (ImGui::Button(str_about.c_str()))
    {
        _show_about = true;
    }

    ImGui::End(); // Main window
}

void gui::_close_all_cipher_windows()
{
    _show_additive_cipher = false;
    _show_multiplicative_cipher = false;
    _show_affine_cipher = false;
    _show_autokey_cipher = false;
    _show_playfair_cipher = false;
    _show_vigenere_cipher = false;
    _show_hill_cipher = false;
    _show_transposition_cipher = false;
}

void gui::additive_cipher()
{
    if(_show_additive_cipher)
    {
        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_NoScrollbar;
        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoResize;
        window_flags |= ImGuiWindowFlags_NoCollapse;

        ImVec2 pos = ImVec2(4 + _main_window_size.x,0);


        ImGui::SetNextWindowPos(pos);

        ImGui::Begin("Additive cipher", &_show_additive_cipher, window_flags);

        ImGui::Text("Alphabet");
        ImGui::Separator();
        ImGui::InputTextWithHint("Alphabet", "enter alphabet here", &_additive_alphabet);

        ImGui::Text("Reset alphabet:");
        ImGui::SameLine();

        std::string str_original_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
        std::string str_eng_small_alphabet = "abcdefghijklmnopqrstuvwxyz";
        std::string str_eng_big_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string str_eng_all_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .!@#$%^&*()_-+=\'\\|/";

        std::string str_original =  "Original";
        std::string str_eng_small = "Small   ";
        std::string str_eng_big =   "Big     ";
        std::string str_eng_all =   "All     ";

        if(ImGui::Button(str_original.c_str()))
        {
            _additive_alphabet = str_original_alphabet;
        }
        ImGui::SameLine();

        if(ImGui::Button(str_eng_small.c_str()))
        {
            _additive_alphabet = str_eng_small_alphabet;
        }
        ImGui::SameLine();

        if(ImGui::Button(str_eng_big.c_str()))
        {
            _additive_alphabet = str_eng_big_alphabet;
        }
        ImGui::SameLine();

        if(ImGui::Button(str_eng_all.c_str()))
        {
            _additive_alphabet = str_eng_all_alphabet;
        }

        ImGui::InputTextWithHint("Key", "enter key", &_additive_str_key);

        std::string _s_key = "Key: ";
        _s_key += std::to_string(_additive_key);
        ImGui::Text(_s_key.c_str());

        ImGui::Spacing();
        ImGui::Text("Encrypt");
        ImGui::Separator();



        ImGui::InputTextWithHint("Text to encrypt", "enter text to encrypt here", &_additive_source_text);

        try
        {
            _additive_key = std::stoi(_additive_str_key);
        }
        catch(const std::exception& e)
        {
            _additive_key = 0;
            spdlog::error(e.what());
        }

        if(ImGui::Button("Encrypt"))
        {
            ad.set_alphabet(_additive_alphabet);
            ad.set_source_text(_additive_source_text);

            ad.set_key(_additive_key);

            ad.encrypt();

            _additive_cipher_text = ad.get_cipher_text();
        }

        std::string str_cipher_text = "Cipher text: ";
        str_cipher_text += ad.get_cipher_text();

        ImGui::Text(str_cipher_text.c_str());

        ImGui::Spacing();
        ImGui::Text("Decrypt");
        ImGui::Separator();

        ImGui::InputTextWithHint("Text to decrypt", "enter text to decrypt here", &_additive_cipher_text);

        if(ImGui::Button("Decrypt"))
        {
            ad.set_cipher_text(_additive_cipher_text);
            ad.set_key(_additive_key);

            ad.decrypt();

            _additive_source_text = ad.get_source_text();
        }

        std::string str_source_text = "Source text: ";
        str_source_text += ad.get_source_text();

        ImGui::Text(str_source_text.c_str());

        ImGui::SetWindowSize(_additive_window_size);

        ImGui::End(); // Additive cipher
    }
}

void gui::multiplicative_cipher()
{
    if(_show_multiplicative_cipher)
    {
        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_NoScrollbar;
        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoResize;
        window_flags |= ImGuiWindowFlags_NoCollapse;

        ImVec2 pos = ImVec2(4 + _main_window_size.x,0);


        ImGui::SetNextWindowPos(pos);

        ImGui::Begin("Multiplicative cipher", &_show_multiplicative_cipher, window_flags);

        ImGui::Text("Alphabet");
        ImGui::Separator();
        ImGui::InputTextWithHint("Alphabet", "enter alphabet here", &_additive_alphabet);

        ImGui::Text("Reset alphabet:");
        ImGui::SameLine();

        std::string str_original_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
        std::string str_eng_small_alphabet = "abcdefghijklmnopqrstuvwxyz";
        std::string str_eng_big_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string str_eng_all_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .!@#$%^&*()_-+=\'\\|/";

        std::string str_original =  "Original";
        std::string str_eng_small = "Small   ";
        std::string str_eng_big =   "Big     ";
        std::string str_eng_all =   "All     ";

        if(ImGui::Button(str_original.c_str()))
        {
            _additive_alphabet = str_original_alphabet;
        }
        ImGui::SameLine();

        if(ImGui::Button(str_eng_small.c_str()))
        {
            _additive_alphabet = str_eng_small_alphabet;
        }
        ImGui::SameLine();

        if(ImGui::Button(str_eng_big.c_str()))
        {
            _additive_alphabet = str_eng_big_alphabet;
        }
        ImGui::SameLine();

        if(ImGui::Button(str_eng_all.c_str()))
        {
            _additive_alphabet = str_eng_all_alphabet;
        }

        ImGui::InputTextWithHint("Key", "enter key", &_additive_str_key);

        std::string _s_key = "Key: ";
        _s_key += std::to_string(_additive_key);
        ImGui::Text(_s_key.c_str());
        ImGui::SameLine();
        _help_marker(
                "The number should be able to take the inverse modulus.\n"
                "Example numbers: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 , 97, 101, 103, 107, 109, 113, 127...\n");

        ImGui::Spacing();
        ImGui::Text("Encrypt");
        ImGui::Separator();



        ImGui::InputTextWithHint("Text to encrypt", "enter text to encrypt here", &_additive_source_text);

        try
        {
            _additive_key = std::stoi(_additive_str_key);
        }
        catch(const std::exception& e)
        {
            _additive_key = 0;
            spdlog::error(e.what());
        }

        if(ImGui::Button("Encrypt"))
        {
            mp.set_alphabet(_additive_alphabet);
            mp.set_source_text(_additive_source_text);

            mp.set_key(_additive_key);

            mp.encrypt();

            _additive_cipher_text = mp.get_cipher_text();
        }

        std::string str_cipher_text = "Cipher text: ";
        str_cipher_text += mp.get_cipher_text();

        ImGui::Text(str_cipher_text.c_str());

        ImGui::Spacing();
        ImGui::Text("Decrypt");
        ImGui::Separator();

        ImGui::InputTextWithHint("Text to decrypt", "enter text to decrypt here", &_additive_cipher_text);

        if(ImGui::Button("Decrypt"))
        {
            mp.set_cipher_text(_additive_cipher_text);
            mp.set_key(_additive_key);

            mp.decrypt();

            _additive_source_text = mp.get_source_text();
        }

        std::string str_source_text = "Source text: ";
        str_source_text += mp.get_source_text();

        ImGui::Text(str_source_text.c_str());

        ImGui::SetWindowSize(_additive_window_size);

        ImGui::End(); // Additive cipher
    }
}
void gui::affine_cipher()
{
    if(_show_affine_cipher)
    {
        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_NoScrollbar;
        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoResize;
        window_flags |= ImGuiWindowFlags_NoCollapse;

        ImVec2 pos = ImVec2(4 + _main_window_size.x,0);
        ImGui::SetNextWindowPos(pos);

        ImGui::Begin("Affine cipher", &_show_affine_cipher, window_flags);

        // if (true)
        // {
        //     ImVec2 size = ImGui::GetWindowSize();
        //     spdlog::info("size x={} y={}", size.x, size.y);
        // }

        ImGui::Text("Alphabet");
        ImGui::Separator();
        ImGui::InputTextWithHint("Alphabet", "enter alphabet here", &_additive_alphabet);

        ImGui::Text("Reset alphabet:");
        ImGui::SameLine();

        std::string str_original_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
        std::string str_eng_small_alphabet = "abcdefghijklmnopqrstuvwxyz";
        std::string str_eng_big_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string str_eng_all_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .!@#$%^&*()_-+=\'\\|/";

        std::string str_original =  "Original";
        std::string str_eng_small = "Small   ";
        std::string str_eng_big =   "Big     ";
        std::string str_eng_all =   "All     ";

        if(ImGui::Button(str_original.c_str()))
        {
            _additive_alphabet = str_original_alphabet;
        }
        ImGui::SameLine();

        if(ImGui::Button(str_eng_small.c_str()))
        {
            _additive_alphabet = str_eng_small_alphabet;
        }
        ImGui::SameLine();

        if(ImGui::Button(str_eng_big.c_str()))
        {
            _additive_alphabet = str_eng_big_alphabet;
        }
        ImGui::SameLine();

        if(ImGui::Button(str_eng_all.c_str()))
        {
            _additive_alphabet = str_eng_all_alphabet;
        }

        ImGui::InputTextWithHint("Key 1", "enter key 1", &_affine_str_key_1);
        ImGui::InputTextWithHint("Key 2", "enter key 2", &_affine_str_key_2);

        std::string _s_key = "Key1: ";
        _s_key += std::to_string(_affine_key_1);
        _s_key += " key2: ";
        _s_key += std::to_string(_affine_key_2);

        ImGui::Text(_s_key.c_str());
        ImGui::SameLine();
        _help_marker(
                "The number should be able to take the inverse modulus.\n"
                "Example numbers: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 , 97, 101, 103, 107, 109, 113, 127...\n");

        ImGui::Spacing();
        ImGui::Text("Encrypt");
        ImGui::Separator();

        ImGui::InputTextWithHint("Text to encrypt", "enter text to encrypt here", &_additive_source_text);

        try
        {
            _affine_key_1 = std::stoi(_affine_str_key_1);
            _affine_key_2 = std::stoi(_affine_str_key_2);
        }
        catch(const std::exception& e)
        {
            _affine_key_1 = 3;
            _affine_key_2 = 5;
            spdlog::error(e.what());
        }

        if(ImGui::Button("Encrypt"))
        {
            af.set_alphabet(_additive_alphabet);
            af.set_source_text(_additive_source_text);

            af.set_key_a(_affine_key_1);
            af.set_key_b(_affine_key_2);

            af.encrypt();

            _additive_cipher_text = af.get_cipher_text();
        }

        std::string str_cipher_text = "Cipher text: ";
        str_cipher_text += af.get_cipher_text();

        ImGui::Text(str_cipher_text.c_str());

        ImGui::Spacing();
        ImGui::Text("Decrypt");
        ImGui::Separator();

        ImGui::InputTextWithHint("Text to decrypt", "enter text to decrypt here", &_additive_cipher_text);

        if(ImGui::Button("Decrypt"))
        {
            af.set_cipher_text(_additive_cipher_text);

            af.set_key_a(_affine_key_1);
            af.set_key_b(_affine_key_2);

            af.decrypt();

            _additive_source_text = af.get_source_text();
        }

        std::string str_source_text = "Source text: ";
        str_source_text += af.get_source_text();

        ImGui::Text(str_source_text.c_str());

        ImGui::SetWindowSize(_affine_window_size);

        ImGui::End(); // Additive cipher
    }
}

void gui::autokey_cipher()
{
    if(_show_autokey_cipher)
    {

    }
}

void gui::playfair_cipher()
{
    if(_show_playfair_cipher)
    {

    }
}

void gui::vigenere_cipher()
{
    if(_show_vigenere_cipher)
    {

    }
}

void gui::hill_cipher()
{
    if(_show_hill_cipher)
    {

    }
}

void gui::transposition_cipher()
{
    if(_show_transposition_cipher)
    {

    }
}