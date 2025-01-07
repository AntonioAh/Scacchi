#ifndef PEZZO_H
#define PEZZO_H

#include <array>
#include <memory>
#include <utils.hpp>

class Pezzo{


public:
    Pezzo(int riga, int colonna, const Colore& colore, int valore);
    virtual bool muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera);

    const Colore& getColore();
protected:
    int riga;
    int colonna;
    const Colore& colore;
    const int valore;

private:


};

#endif
