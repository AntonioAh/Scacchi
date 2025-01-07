#include <re.hpp>

Re::Re(int riga, int colonna, const Colore& colore) : Pezzo(riga, colonna, colore, 1){

}

bool Re::muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera){
    return false;
}
