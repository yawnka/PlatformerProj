#include "MainMenu.h"
#include "Utility.h"

void MainMenu::initialise() {
    m_game_state.next_scene_id = -1;
    m_game_state.player = nullptr;  // No player in the menu
    m_game_state.enemies = nullptr; // No enemies in the menu
    m_game_state.map = nullptr;     // No map in the menu
}

void MainMenu::update(float delta_time) {
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_RETURN]) {
        m_game_state.next_scene_id = 0;
    }
}

void MainMenu::render(ShaderProgram *program) {
    //glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // grey Solid color background
    //glClearColor(1.1f, 1.1f, 1.1f, 1.0f); // white Solid color background
    glClearColor(0.8f, 0.9f, 0.75f, 1.0f); // Light matcha green Solid color background

    glClear(GL_COLOR_BUFFER_BIT);

    glm::vec3 title_position = glm::vec3(1.0f, -1.0f, 0.0f);
    Utility::draw_text(program, Utility::load_texture("assets/font1.png"), "Jungle Adventure!", 0.4f, 0.02f, title_position);

    glm::vec3 prompt_position = glm::vec3(1.0f, -2.0f, 0.0f);
    Utility::draw_text(program, Utility::load_texture("assets/font1.png"), "Press Enter to Start:", 0.4f, 0.02f, prompt_position);
    
    Utility::draw_text(program, Utility::load_texture("assets/font1.png"), "Note: When you die and respawn", 0.3f, 0.02f, glm::vec3(0.5f, -4.0f, 0.0f));
    Utility::draw_text(program, Utility::load_texture("assets/font1.png"), ",click the move right button", 0.3f, 0.02f, glm::vec3(0.5f, -5.0f, 0.0f));
    Utility::draw_text(program, Utility::load_texture("assets/font1.png"), "& you should drop down!", 0.3f, 0.02f, glm::vec3(0.5f, -6.0f, 0.0f));
}
