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

    void mouseCallback(int button, int action, int mods);
    void keyCallback(int key, int scancode, int action, int mods);


    void render(GLFWwindow *window);
    void destroy();


private:
    unsigned int VAO;

    std::array<std::unique_ptr<Pezzo> , 64> scacchiera;

    //verifica se una mossa e' fattibile (const Casella di arrivo vuota o avversaria)
    bool mossaValida(int rigaPartenza, int colonnaPartenza, int rigaArrivo, int colonnaArrivo);



    Colore& turno;

    Colore bianco = Colore::BIANCO;
    Colore nero = Colore::NERO;
};



#endif
