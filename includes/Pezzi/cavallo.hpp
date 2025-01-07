#ifndef CAVALLO_H
#define CAVALLO_H

#include <pezzo.hpp>

class Cavallo : public Pezzo{
public:
    Cavallo(int riga, int colonna, const Colore& colore);
    bool muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera) override;

private:

};

#endif
