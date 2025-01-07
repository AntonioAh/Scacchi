#include <cavallo.hpp>

Cavallo::Cavallo(int riga, int colonna, const Colore& colore) : Pezzo(riga, colonna, colore, 1){

}

bool Cavallo::muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera){
    return false;
}
