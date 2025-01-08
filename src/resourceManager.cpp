#include "shader.hpp"
#include <resourceManager.hpp>

std::map<std::string, Shader> ResourceManager::shaders;

ResourceManager::ResourceManager(){

}

Shader ResourceManager::loadShader(const std::string& name, const std::string &vertexFile, const std::string &fragmentFile){
    shaders[name] = loadShaderFromFile(vertexFile, fragmentFile);

    return shaders[name];
}

Shader ResourceManager::GetShader(std::string name){
    return shaders[name];
}

Shader ResourceManager::loadShaderFromFile(const std::string& vertexFile, const std::string& fragmentFile){
    Shader shader;
    shader.compile(vertexFile, fragmentFile);
    return shader;
}
