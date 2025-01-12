#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

class Texture{
public:
    unsigned int id;
    unsigned int width, height;
    unsigned int internal_format, image_format;

    unsigned int wrap_s, wrap_t;
    unsigned int filter_min, filter_max;

    Texture();
    void generate(unsigned int width, unsigned int height, unsigned char *data);
    void bind() const ;
};


#endif
