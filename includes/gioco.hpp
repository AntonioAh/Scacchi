#ifndef GIOCO_H
#define GIOCO_H

#include <memory>
#include <utils.hpp>
#include <pezzo.hpp>


#include <array>

class Gioco
{
public:
    Gioco();
private:
    std::array<std::unique_ptr<Pezzo> , 64> scacchiera;

    //verifica se una mossa e' fattibile (const Casella di arrivo vuota o avversaria)
    bool mossaValida(int rigaPartenza, int colonnaPartenza, int rigaArrivo, int colonnaArrivo);



    Colore& turno = bianco;

    Colore bianco = Colore::BIANCO;
    Colore nero = Colore::NERO;
};



#endif
