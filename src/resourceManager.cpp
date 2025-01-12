#include <resourceManager.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

std::map<std::string, Shader> ResourceManager::shaders;
std::map<std::string, Texture> ResourceManager::textures;

ResourceManager::ResourceManager(){

}

Shader ResourceManager::loadShader(const std::string& name, const std::string &vertexFile, const std::string &fragmentFile){
    shaders[name] = loadShaderFromFile(vertexFile, fragmentFile);

    return shaders[name];
}

Shader& ResourceManager::getShader(const std::string& name){
    return shaders[name];
}

Shader ResourceManager::loadShaderFromFile(const std::string& vertexFile, const std::string& fragmentFile){
    Shader shader;
    shader.compile(vertexFile, fragmentFile);
    return shader;
}

Texture ResourceManager::loadTexture(const std::string &name, const std::string &textureFile, bool alpha){
    Texture texture;

    if(alpha){
        texture.internal_format = GL_RGBA;
        texture.image_format = GL_RGBA;
    }
    int width, height, nChannels;
    const char *file = textureFile.c_str();
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(file, &width, &height, &nChannels, 0);

    texture.generate(width, height, data);
    stbi_image_free(data);


    textures[name] = texture;
    return textures[name];
}

Texture& ResourceManager::getTexture(const std::string &name){
    return textures[name];
}
