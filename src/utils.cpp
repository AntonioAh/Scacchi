#include <utils.hpp>

bool operator==(Colore primo, Colore secondo){
    return static_cast<int>(primo) == static_cast<int>(secondo);
}

Casella::Casella () :riga(0), colonna(0), posizione(0){

}

Casella::Casella (int r, int c) : riga(r), colonna(c), posizione(riga * 8 + colonna) {

}

bool Casella::operator==(const Casella& other) const {
    return riga == other.riga && colonna == other.colonna;
}

bool Casella::operator!=(const Casella& other) const {
    return !(*this == other);;
}

Casella Casella::operator+(const Casella& other){
    return {riga + other.riga, colonna + other.colonna};
}

void Casella::calcolaPosizione(){
    posizione = riga * 8 + colonna;
}
