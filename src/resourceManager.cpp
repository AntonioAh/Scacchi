#include "shader.hpp"
#include <resourceManager.hpp>

std::map<std::string, Shader> ResourceManager::shaders;

ResourceManager::ResourceManager(){

}

Shader ResourceManager::loadShader(const std::string& name, const std::string &vertexFile, const std::string &fragmentFile){
    shaders[name] = Shader();
    shaders[name].compile(vertexFile, fragmentFile);
    return shaders[name];
}

Shader ResourceManager::GetShader(std::string name){
    return shaders[name];
}
