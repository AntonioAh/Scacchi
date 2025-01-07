#include <pezzo.hpp>

Pezzo::Pezzo(int riga, int colonna, const Colore& colore, int valore) : riga{riga}, colonna(colonna), colore(colore), valore(valore){

}

bool Pezzo::muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera){
    return false;
}

const Colore& Pezzo::getColore(){
    return colore;
}
