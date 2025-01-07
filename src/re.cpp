#include <re.hpp>

Re::Re(int riga, int colonna, const Colore& colore) : Pezzo(riga, colonna, colore, 1){

}

bool Re::muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera){
    if (abs(riga - arrivo.riga) < 1 && abs(colonna - arrivo.colonna) < 1)
        return false;

    return false;
}
