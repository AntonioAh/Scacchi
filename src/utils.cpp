#include <utils.hpp>

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
