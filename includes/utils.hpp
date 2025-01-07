#ifndef UTILS_H
#define UTILS_H

enum Colore{
    BIANCO, NERO
};

struct Casella{
    int riga, colonna, posizione;
    Casella (int r, int c) : riga(r), colonna(c), posizione(riga * 8 + colonna) {

    }
};

#endif
