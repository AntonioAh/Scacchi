#include "utils.hpp"
#include <resourceManager.hpp>
#include <pezzo.hpp>
#include <glad/glad.h>


#include <glm/gtc/matrix_transform.hpp>

const glm::vec2 Pezzo::size = glm::vec2(0.25f, 0.25f);

Pezzo::Pezzo(int riga, int colonna, const Colore& colore, int valore, const std::string& texture) :
            riga{riga}, colonna(colonna), colore(colore), valore(valore), texture(ResourceManager::getTexture(texture)),
            shader(ResourceManager::getShader("pezzo")){

    mosso = true;
}

bool Pezzo::muovi(const Casella& arrivo, std::array<std::unique_ptr<Pezzo>, 64>& scacchiera){
    return false;
}

const Colore Pezzo::getColore(){
    return colore;
}

void Pezzo::render(){
    float posizioneX = ((2.0f / 8) * colonna) - 1.0f;
    float posizioneY =((-2.0f / 8) * riga ) + 1.0f;

    glm::vec2 position = glm::vec2(posizioneX, posizioneY);

    if (mosso){
        float verteces[] = {
            posizioneX, posizioneY, 0.0f, 0.5f,
            posizioneX + size.x, posizioneY, 0.5f, 0.5f,
            posizioneX, posizioneY - size.y, 0.0f, 0.0f,
            posizioneX + size.x, posizioneY - size.y, 0.5f, 0.0f
        };

        unsigned int VBO;
        glGenVertexArrays(1, &(this->VAO));
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verteces), verteces, GL_STATIC_DRAW);

        glBindVertexArray(this->VAO);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        mosso = false;
    }

    this->shader.use();

    glActiveTexture(GL_TEXTURE0);
    this->texture.bind();

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);
}

Pezzo::~Pezzo(){
    glDeleteVertexArrays(1, &(this->VAO));
}

void Pezzo::setPosizione(const Casella& arrivo){
    this->riga = arrivo.riga;
    this->colonna = arrivo.colonna;
}
