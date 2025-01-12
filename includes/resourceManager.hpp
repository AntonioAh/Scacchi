#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <glad/glad.h>
#include <map>
#include <string>

#include <shader.hpp>
#include <texture.hpp>

class ResourceManager{
public:
    static std::map<std::string, Shader> shaders;
    static std::map<std::string, Texture> textures;

    static Shader loadShader(const std::string& name, const std::string& vertexFile, const std::string& fragmentFile);
    static Shader& getShader(const std::string& name);

    static Texture loadTexture(const std::string& name, const std::string& textureFile, bool alpha = false);
    static Texture& getTexture(const std::string& name);


private:
    ResourceManager();

    static Shader loadShaderFromFile(const std::string& vertexFile, const std::string& fragmentFile);
};

#endif
