#include <torre.hpp>

Torre::Torre(int riga, int colonna, const Colore& colore) : Pezzo(riga, colonna, colore, 1){

}

bool Torre::muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera){
    if (riga == arrivo.riga){
        int minimo = colonna < arrivo.colonna ? colonna : arrivo.colonna;
        int massimo = colonna > arrivo.colonna ? colonna : arrivo.colonna;

        for (int i = minimo+1; i < massimo; i++)
            if (!scacchiera[riga * 8 + i].get())
                return false;

        return true;
    }
    else if (colonna == arrivo.colonna){
        int minimo = riga < arrivo.riga ? riga : arrivo.riga;
        int massimo = riga > arrivo.riga ? riga : arrivo.riga;

        for (int i = minimo+1; i < massimo; i++)
            if (!scacchiera[i * 8 + colonna].get())
                return false;

        return true;
    }

    return false;
}
