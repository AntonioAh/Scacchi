#ifndef GIOCO_H
#define GIOCO_H

#include <GLFW/glfw3.h>


#include <memory>
#include <utils.hpp>
#include <pezzo.hpp>


#include <array>

class Gioco
{
public:
    Gioco();
    void init();

    bool shouldClose;

    void mouseCallback(GLFWwindow *window, int button, int action, int mods);
    void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);


    void render(GLFWwindow *window);
    void destroy();


private:
    unsigned int VAO;

    std::array<std::unique_ptr<Pezzo> , 64> scacchiera;

    //verifica se una mossa e' fattibile (const Casella di arrivo vuota o avversaria)
    bool mossaValida(const Casella& partenza, const Casella& arrivo);

    bool daMuovere;
    Casella partenza;
    Casella arrivo;
    void aggiornaPezzo(const Casella& partenza, const Casella& arrivo);

    Colore turno;
};



#endif
