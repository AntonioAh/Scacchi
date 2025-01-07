#ifndef REGINA_H
#define REGINA_H

#include <pezzo.hpp>

class Regina : public Pezzo{
public:
    Regina(int riga, int colonna, const Colore& colore);
    bool muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera) override;

private:

};

#endif
