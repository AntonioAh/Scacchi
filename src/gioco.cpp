#include "resourceManager.hpp"
#include <sys/_types/_sigaltstack.h>
#include <utils.hpp>
#include <gioco.hpp>
#include <resourceManager.hpp>
#include <memory>

#include <iostream>

#include <pedone.hpp>
#include <torre.hpp>
#include <cavallo.hpp>
#include <alfiere.hpp>
#include <regina.hpp>
#include <re.hpp>


Gioco::Gioco() : shouldClose(false), turno(Colore::BIANCO){
    daMuovere = false;
}

void Gioco::init(){
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



    ResourceManager::loadShader("scacchiera", "../Shaders/scacchiera.vs", "../Shaders/scacchiera.fs");
    ResourceManager::loadShader("pezzo", "../Shaders/pezzo.vs", "../Shaders/pezzo.fs");

    ResourceManager::loadTexture("pedone-bianco", "../Textures/pawn-white.png", true);

    for (int i = 0; i < 8; i++){
        scacchiera[48 + i] = std::make_unique<Pedone>(6, i, Colore::BIANCO, "pedone-bianco");
         scacchiera[8 + i] = std::make_unique<Pedone>(1, i, Colore::NERO, "pedone-bianco");
    }

    // scacchiera[0] = std::make_unique<Torre>(0, 0, nero);
    // scacchiera[1] = std::make_unique<Cavallo>(0, 1, nero);
    // scacchiera[2] = std::make_unique<Alfiere>(0, 2, nero);
    // scacchiera[3] = std::make_unique<Regina>(0, 3, nero);
    // scacchiera[4] = std::make_unique<Re>(0, 4, nero);
    // scacchiera[5] = std::make_unique<Alfiere>(0, 5, nero);
    // scacchiera[6] = std::make_unique<Cavallo>(0, 6, nero);
    // scacchiera[7] = std::make_unique<Torre>(0, 7, nero);


    // scacchiera[56] = std::make_unique<Torre>(7, 0, bianco);
    // scacchiera[57] = std::make_unique<Cavallo>(7, 1, bianco);
    // scacchiera[58] = std::make_unique<Alfiere>(7, 2, bianco);
    // scacchiera[59] = std::make_unique<Regina>(7, 3, bianco);
    // scacchiera[60] = std::make_unique<Re>(7, 4, bianco);
    // scacchiera[61] = std::make_unique<Alfiere>(7, 5, bianco);
    // scacchiera[62] = std::make_unique<Cavallo>(7, 6, bianco);
    // scacchiera[63] = std::make_unique<Torre>(7, 7, bianco);

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

void Gioco::mouseCallback(GLFWwindow *window, int button, int action, int mods){
    double xCursor, yCursor;
    glfwGetCursorPos(window, &xCursor, &yCursor);

    if (button == GLFW_MOUSE_BUTTON_LEFT && !daMuovere && action == GLFW_PRESS){
        partenza.riga = static_cast<int>(yCursor / 100);
        partenza.colonna = static_cast<int>(xCursor / 100);
        partenza.calcolaPosizione();

        std::cout << "Partenza : " <<  partenza.riga << " " << partenza.colonna << "\n";
        //std::cout <<

        if (scacchiera[partenza.posizione] && scacchiera[partenza.posizione]->getColore() == turno){
            std::cout << "rotvato\n";
            daMuovere = true;
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && daMuovere && action == GLFW_PRESS){
        arrivo.riga = static_cast<int>(yCursor / 100);
        arrivo.colonna = static_cast<int>(xCursor / 100);
        arrivo.calcolaPosizione();

        std::cout << "Arrivo" << arrivo.riga << " " << arrivo.colonna << "\n";

        daMuovere = false;
        if (mossaValida(partenza, arrivo)){
            std::cout << "giusto\n";

            aggiornaPezzo(partenza, arrivo);

            if (turno == Colore::BIANCO)
                turno = Colore::NERO;
            else
                turno = Colore::BIANCO;

            std::cout << "Turno : " << (turno == Colore::BIANCO ? "Bianco" : "Nero") << "\n";
            scacchiera[arrivo.posizione]->mosso = true;
            render(window);
        }
    }
}

void Gioco::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        shouldClose = true;
    }
}

bool Gioco::mossaValida(const Casella& partenza, const Casella& arrivo){

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

    ResourceManager::getShader("scacchiera").use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);

    for (int i = 0; i < 64; i++){
        if (scacchiera[i].get())
            scacchiera[i]->render();
    }

    glfwSwapBuffers(window);
    glfwWaitEvents();
}

void Gioco::aggiornaPezzo(const Casella& partenza, const Casella& arrivo){
    if (scacchiera[arrivo.posizione].get()){
        scacchiera[arrivo.posizione].reset();
    }

    scacchiera[arrivo.posizione] = std::move(scacchiera[partenza.posizione]);
    scacchiera[partenza.posizione] = nullptr;

    scacchiera[arrivo.posizione]->setPosizione(arrivo);
}
