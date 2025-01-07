#ifndef TORRE_H
#define TORRE_H

#include <pezzo.hpp>

class Torre : public Pezzo{
public:
    Torre(int riga, int colonna, const Colore& colore);
    bool muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera) override;

private:

};

#endif
