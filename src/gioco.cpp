
#include "utils.hpp"
#include <gioco.hpp>
#include <memory>

#include <pedone.hpp>
#include <torre.hpp>
#include <cavallo.hpp>
#include <alfiere.hpp>
#include <regina.hpp>
#include <re.hpp>

Gioco::Gioco(){
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
    scacchiera[66] = std::make_unique<Torre>(7, 7, bianco);
}


bool Gioco::mossaValida(int rigaPartenza, int colonnaPartenza, int rigaArrivo, int colonnaArrivo){
    Casella partenza(rigaPartenza, colonnaPartenza);
    Casella arrivo(rigaArrivo , colonnaArrivo);

    if (!scacchiera[arrivo.posizione] || scacchiera[arrivo.posizione]->getColore() != scacchiera[partenza.posizione]->getColore()){
        return scacchiera[partenza.posizione]->muovi(arrivo, scacchiera);
    }
    return false;
}
