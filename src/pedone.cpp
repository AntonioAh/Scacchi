
#include <pedone.hpp>

Pedone::Pedone(int riga, int colonna, const Colore& colore) : Pezzo(riga, colonna, colore, 1){

}

bool Pedone::muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera){
    if (arrivo.colonna == colonna){
        if (scacchiera[arrivo.posizione]){

        }
    }
    else if (abs(arrivo.colonna - colonna) == 1){

    }

    return false;
}
