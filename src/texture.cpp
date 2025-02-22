#include <texture.hpp>

Texture::Texture() : width(0), height(0), internal_format(GL_RGB), image_format(GL_RGB), wrap_s(GL_CLAMP_TO_EDGE), wrap_t(GL_CLAMP_TO_EDGE), filter_max(GL_LINEAR), filter_min(GL_LINEAR){

}

void Texture::generate(unsigned int width, unsigned int height, unsigned char *data){
    this->width = width;
    this->height = height;

    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexImage2D(GL_TEXTURE_2D, 0, this->internal_format, width, height, 0, this->image_format, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrap_s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrap_t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filter_min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filter_max);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, this->id);
}
