#include "utils.hpp"
#include <cavallo.hpp>
#include <array>

Cavallo::Cavallo(int riga, int colonna, const Colore& colore) : Pezzo(riga, colonna, colore, 1){

}

bool Cavallo::muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera){
    std::array<Casella, 8> possibili {{
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, -2}, {1, 2}, {-1, 2}, {-1, -2}
    }};

    for (const auto& casella : possibili){
        if (casella.riga + riga < 7 && casella.riga + riga >= 0 && casella.colonna + colonna < 7 && casella.colonna + colonna >= 0)
            if (casella == arrivo)
                return true;
    }
    return false;
}
