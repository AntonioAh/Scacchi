#include "resourceManager.hpp"
#include <utils.hpp>
#include <gioco.hpp>
#include <resourceManager.hpp>
#include <memory>

#include <pedone.hpp>
#include <torre.hpp>
#include <cavallo.hpp>
#include <alfiere.hpp>
#include <regina.hpp>
#include <re.hpp>

Gioco::Gioco() : turno(bianco), shouldClose(false){

}

void Gioco::init(){
    for (int i = 0; i < 8; i++){
        scacchiera[48 + i] = std::make_unique<Pedone>(6, i, bianco);
        scacchiera[8 + 1] = std::make_unique<Pedone>(1, i, nero);
    }

    scacchiera[0] = std::make_unique<Torre>(0, 0, nero);
    scacchiera[1] = std::make_unique<Cavallo>(0, 1, nero);
    scacchiera[2] = std::make_unique<Alfiere>(0, 2, nero);
    scacchiera[3] = std::make_unique<Regina>(0, 3, nero);
    scacchiera[4] = std::make_unique<Re>(0, 4, nero);
    scacchiera[5] = std::make_unique<Alfiere>(0, 5, nero);
    scacchiera[6] = std::make_unique<Cavallo>(0, 6, nero);
    scacchiera[7] = std::make_unique<Torre>(0, 7, nero);


    scacchiera[56] = std::make_unique<Torre>(7, 0, bianco);
    scacchiera[57] = std::make_unique<Cavallo>(7, 1, bianco);
    scacchiera[58] = std::make_unique<Alfiere>(7, 2, bianco);
    scacchiera[59] = std::make_unique<Regina>(7, 3, bianco);
    scacchiera[60] = std::make_unique<Re>(7, 4, bianco);
    scacchiera[61] = std::make_unique<Alfiere>(7, 5, bianco);
    scacchiera[62] = std::make_unique<Cavallo>(7, 6, bianco);
    scacchiera[63] = std::make_unique<Torre>(7, 7, bianco);

    ResourceManager::loadShader("scacchiera", "../Shaders/scacchiera.vs", "../Shaders/scacchiera.fs");
    float verteces[] = {
        -1.0f, -1.0f,
        -1.0f, 1.0f,
        1.0f, -1.0f,
        1.0f, 1.0f
    };

    unsigned int VBO;
    glGenVertexArrays(1, &(this->VAO));
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verteces), verteces, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    glDeleteBuffers(1, &VBO);
}

void Gioco::mouseCallback(int button, int action, int mods){

}

void Gioco::keyCallback(int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        shouldClose = true;
    }
}

bool Gioco::mossaValida(int rigaPartenza, int colonnaPartenza, int rigaArrivo, int colonnaArrivo){
    Casella partenza(rigaPartenza, colonnaPartenza);
    Casella arrivo(rigaArrivo , colonnaArrivo);

    if (!scacchiera[arrivo.posizione] || scacchiera[arrivo.posizione]->getColore() != scacchiera[partenza.posizione]->getColore()){
        return scacchiera[partenza.posizione]->muovi(arrivo, scacchiera);
    }
    return false;
}

void Gioco::render(GLFWwindow *window){
    if (glfwWindowShouldClose(window)){
        shouldClose = true;
        return ;
    }
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ResourceManager::GetShader("scacchiera").use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);

    glfwSwapBuffers(window);
    glfwWaitEvents();
}
