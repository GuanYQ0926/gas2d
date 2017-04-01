#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H

#include "glinclude.h"

#include <string>
using std::string;
#include <glm/glm.hpp>
using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat4;
using glm::mat3;

namespace GLSLShader{
    enum GLSLShaderType{
        VERTEX, FRAGMENT
    };
};

class GLSLProgram
{
private:
    int handle;
    bool linked;
    string logString;

    int getUniformLocation(const char* name);
    bool fileExists(const string& filename);

public:
    GLSLProgram();

    bool compileShaderFromFile(const char* filename, GLSLShader::GLSLShaderType type);
    bool compileShaderFromString(const string& source, GLSLShader::GLSLShaderType type);
    bool link();
    void use();

    string log();
    int getHandle();
    bool isLinked();

    void setUniform(const char* name, float x, float y, float z);
    void setUniform(const char* name, const vec2& v);
    void setUniform(const char* name, const vec3& v);
    void setUniform(const char* name, const vec4& v);
    void setUniform(const char* name, const mat4& m);
    void setUniform(const char* name, const mat3& m);
    void setUniform(const char* name, float val);
    void setUniform(const char* name, int val);
    void setUniform(const char* name, bool val);

};

#endif
