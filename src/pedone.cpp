
#include <pedone.hpp>

Pedone::Pedone(int riga, int colonna, const Colore& colore, const std::string& texture) :
    Pezzo(riga, colonna, colore, 1, texture){

}

bool Pedone::muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera){
    int verso = colore == Colore::BIANCO ? -1 : 1;

    if (arrivo.colonna == colonna){
        if (!scacchiera[arrivo.posizione]){
            int diff = (arrivo.riga - riga) * verso;

            if (diff == 1){
                return true;
            }

            bool seconda = colore == Colore::BIANCO ? riga == 6 : riga == 1;
            if (diff == 2 && seconda && !scacchiera[arrivo.posizione  - 8 * verso])
                return true;
        }
    }
    else if (abs(arrivo.colonna - colonna) == 1){
        if (arrivo.riga - riga == verso && scacchiera[arrivo.posizione].get())
            return true;
    }

    return false;
}
