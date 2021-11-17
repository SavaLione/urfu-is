#include "core/gui.h"
#include "core/compiler_version.h"
#include "io/logger.h"

static void glfw_error_callback(int error, const char *description)
{
    spdlog::error("Glfw Error {}: {}", error, description);
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
        ImGui::Begin("About", &_show_about);

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
    ImGui::Begin("Main window");

    ImGui::End();
}