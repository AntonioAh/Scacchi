#ifndef UTILS_H
#define UTILS_H

enum Colore{
    BIANCO, NERO
};

bool operator==(Colore primo, Colore secondo);

struct Casella{
    int riga, colonna, posizione;

    Casella();
    Casella (int r, int c);
    bool operator==(const Casella& other) const;
    bool operator!=(const Casella& other) const;
    Casella operator+(const Casella& other);
    void calcolaPosizione();

};

#endif
