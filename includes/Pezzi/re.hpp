#ifndef RE_H
#define RE_H

#include <pezzo.hpp>

class Re : public Pezzo{
public:
    Re(int riga, int colonna, const Colore& colore);
    bool muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera) override;

private:

};

#endif
