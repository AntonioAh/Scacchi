#include <shader.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(){

}

Shader& Shader::use(){
    glUseProgram(this->id);
    return *this;
}

void Shader::compile(const std::string& nameFileVertex, const std::string& nameFileFragment){
    std::ifstream fileVertex(nameFileVertex), fileFragment(nameFileFragment);


    if (!fileVertex.is_open()){
        std::cerr << "Impossibile aprire file " << nameFileVertex << "\n";
        return ;
    }

    if (!fileFragment.is_open()){
            std::cerr << "Impossibile aprire file " << nameFileFragment << "\n";
            return ;
    }

    std::stringstream streamVertex, streamFragment;
    streamVertex << fileVertex.rdbuf();
    streamFragment << fileFragment.rdbuf();

    fileVertex.close();
    fileFragment.close();

    std::string strVertex = streamVertex.str(), strFragment = streamFragment.str();
    const char *vertexCode = strVertex.c_str();
    const char *fragmentCode = strFragment.c_str();

    std :: cout << "arrivato\n";
    unsigned int vertexId, fragmentId;

    vertexId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexId, 1, &vertexCode, nullptr);
    glCompileShader(vertexId);
    checkCompileErrors(vertexId);

    fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentId, 1, &fragmentCode, nullptr);
    glCompileShader(fragmentId);
    checkCompileErrors(fragmentId);

    this->id = glCreateProgram();
    glAttachShader(this->id, vertexId);
    glAttachShader(this->id, fragmentId);
    glLinkProgram(this->id);
    checkCompileErrors(this->id, true);


    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);

}

void Shader::checkCompileErrors(unsigned int object, bool isProgram){
    int success;
    char infoLog[1024];

    if (isProgram){
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if (!success){
            glGetProgramInfoLog(object, 1024, nullptr, infoLog);
            std::cerr << infoLog << "\n";
        }
    }
    else{
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if (!success){
            glGetShaderInfoLog(object, 1024, nullptr, infoLog);
            std::cerr << infoLog << "\n";
        }
    }
}
