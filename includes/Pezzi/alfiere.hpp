#ifndef ALFIERE_H
#define ALFIERE_H

#include "utils.hpp"
#include <pezzo.hpp>

class Alfiere : public Pezzo{
public:
    Alfiere(int riga, int colonna, const Colore& colore);
    bool muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera) override;

private:

};

#endif
