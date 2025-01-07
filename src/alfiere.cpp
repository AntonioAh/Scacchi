#include <alfiere.hpp>

Alfiere::Alfiere(int riga, int colonna, const Colore& colore) : Pezzo(riga, colonna, colore, 1){

}

bool Alfiere::muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera){
    if (abs(arrivo.riga - riga) == abs(arrivo.colonna - colonna)){
        int destra = arrivo.colonna - colonna > 0 ? 1 : -1;
        int basso = arrivo.riga - riga > 0 ? 1 : -1;

        Casella direzione(basso, destra);
        Casella iter(riga, colonna);
        while (iter != arrivo){
            iter = iter + direzione;

            if (scacchiera[iter.riga * 8 + iter.colonna].get())
                return false;
        }

        return true;
    }

    return false;
}
