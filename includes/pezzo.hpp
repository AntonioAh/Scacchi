#ifndef PEZZO_H
#define PEZZO_H

#include <array>
#include <string>
#include <memory>
#include <utils.hpp>

#include <resourceManager.hpp>
#include <texture.hpp>
#include <glm/glm.hpp>

class Pezzo{


public:
    Pezzo(int riga, int colonna, const Colore& colore, int valore, const std::string& texture);
    virtual bool muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera);

    const Colore getColore();
    void setPosizione(const Casella& arrivo);
    void render();

    ~Pezzo();

    bool mosso;
protected:
    int riga;
    int colonna;
    const Colore colore;
    const int valore;


private:
    const Texture& texture;
    const Shader& shader;
    static const glm::vec2 size;

    unsigned int VAO;



};

#endif
