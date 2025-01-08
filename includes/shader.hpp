#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader{
public:
    Shader();
    unsigned int id;

    Shader &use();
    void compile(const std::string& nameFileVertex, const std::string& nameFileFragment);


private:
    void checkCompileErrors(unsigned int object, bool isProgram = false);
};


#endif
