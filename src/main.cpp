#include <glad/glad.h>
#include "GLFW/glfw3.h"

#include <gioco.hpp>

#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

void key_callback_funtion(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouse_callback_funcion(GLFWwindow *window, int button, int action, int mods);

Gioco gioco;

int main(int argc, char *argv[]){
    if (!glfwInit()){
        std::cerr << "Impossibile caricare glfw\n";
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "orthographic cube", nullptr, nullptr);
    if (!window){
        std::cerr << "errore creazione finestra\n";
        return 1;
    }
    glfwMakeContextCurrent(window);

    gioco.init();

    glfwSetKeyCallback(window,  key_callback_funtion);
    glfwSetMouseButtonCallback(window, mouse_callback_funcion);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Errore caricare glad\n";
        return 1;
    }

    while(!gioco.shouldClose){
        //gioco.render();
    }

    // Gioco::destroy();
    return 0;
}

void key_callback_funtion(GLFWwindow *window, int key, int scancode, int action, int mods){
    Gioco::keyCallback(key, scancode, action, mods);
}

void mouse_callback_funcion(GLFWwindow *window, int button, int action, int mods){
    Gioco::mouseCallback(button, action, mods);
}
