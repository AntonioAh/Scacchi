#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>

class Shader{
public:
    Shader();
    unsigned int id;

    const Shader &use() const ;
    void compile(const std::string& nameFileVertex, const std::string& nameFileFragment);

    void SetMatrix4 (const char *name, const glm::mat4& matrice, bool useShader = false) const ;


private:
    void checkCompileErrors(unsigned int object, bool isProgram = false);
};


#endif
