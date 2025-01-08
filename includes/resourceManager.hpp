#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <glad/glad.h>
#include <map>
#include <string>

#include <shader.hpp>

class ResourceManager{
public:
    static std::map<std::string, Shader> shaders;

    static Shader loadShader(const std::string& name, const std::string& vertexFile, const std::string& fragmentFile);

    static Shader GetShader(std::string name);


private:
    ResourceManager();

};

#endif
