#ifndef PEDONE_H
#define PEDONE_H

#include <pezzo.hpp>

class Pedone : public Pezzo{
public:
    Pedone(int riga, int colonna, const Colore& colore, const std::string& texture);
    bool muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera) override;

private:

};

#endif
