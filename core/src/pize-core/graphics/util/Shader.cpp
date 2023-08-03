#ifndef PIZE_CORE_GRAPHICS_UTIL_SHADER
#define PIZE_CORE_GRAPHICS_UTIL_SHADER

#include <glad/glad.h>
#include <map>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <pize-core/math/vecmath/matrix/Matrix4f.cpp>

using namespace std;

class Shader{
private:

    GLuint shader;
    map<string, int> uniforms;
    int num_sampler2D, num_samplerCube, num_sampler2DArray;

public:

    Shader(const GLchar *vertexPath, const GLchar *fragmentPath){
        // 1. Получаем исходный код шейдера из filePath
        string vertexCode;
        string fragmentCode;
        ifstream vShaderFile;
        ifstream fShaderFile;
        // Удостоверимся, что ifstream объекты могут выкидывать исключения
        vShaderFile.exceptions(ifstream::badbit);
        fShaderFile.exceptions(ifstream::badbit);
        try{
            // Открываем файлы
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            stringstream vShaderStream, fShaderStream;
            // Считываем данные в потоки
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // Закрываем файлы
            vShaderFile.close();
            fShaderFile.close();
            // Преобразовываем потоки в массив GLchar
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch(ifstream::failure e){
            cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
        }

        shader = createProgram(vertexCode.c_str(), fragmentCode.c_str());
    }


    void putUniform(const string uniformName){
        const int index = glGetUniformLocation(shader, (&uniformName)->c_str());
        if(index == -1)
            return;

        uniforms.insert( make_pair(uniformName, index) );
    }


    void setUniform(const char *uniformName, float x){
        glUniform1f(uniforms[uniformName], x);
    }

    void setUniform(const char *uniformName, float x, float y){
        glUniform2f(uniforms[uniformName], x, y);
    }

    void setUniform(const char *uniformName, float x, float y, float z){
        glUniform3f(uniforms[uniformName], x, y, z);
    }

    void setUniform(const char *uniformName, float x, float y, float z, float w){
        glUniform4f(uniforms[uniformName], x, y, z, w);
    }

    void setUniform(const char *uniformName, int count, float array[]){
        glUniform1fv(uniforms[uniformName], count, array);
    }

    void setUniform(const char *uniformName, int value){
        glUniform1i(uniforms[uniformName], value);
    }

    void setUniform(const char *uniformName, int count, int array[]){
        glUniform1iv(uniforms[uniformName], count, array);
    }

    void setUniform(const char *uniformName, Texture *texture){
        texture->bind(num_sampler2D);
        glUniform1i(uniforms[uniformName], num_sampler2D);
        num_sampler2D++;
    }

    void setUniform(const char *uniformName, Matrix4f *matrix4f){
        glUniformMatrix4fv(uniforms[uniformName], 1, GL_FALSE, matrix4f->val);
    }

    // void setUniform(const char *uniformName, Vec2f v){
    //     glUniform2f(uniforms[uniformName], v.x, v.y);
    // }

    // void setUniform(const char *uniformName, Vec3f v){
    //     glUniform3f(uniforms[uniformName], v.x, v.y, v.z);
    // }

    // void setUniform(const char *uniformName, IColor color){
    //     glUniform4f(uniforms[uniformName], color.r(), color.g(), color.b(), color.a());
    // }

    // void setUniform(const char *uniformName, TextureArray textureArray){
    //     textureArray.bind(num_sampler2DArray);
    //     glUniform1i(uniforms[uniformName], num_sampler2DArray);
    //     num_sampler2DArray++;
    // }

    // void setUniform(const char *uniformName, CubeMap cubeMap){
    //     cubeMap.bind(num_samplerCube);
    //     glUniform1i(uniforms[uniformName], num_samplerCube);
    //     num_samplerCube++;
    // }


    void bindAttribute(GLuint index, const GLchar *name) const{
        glBindAttribLocation(shader, index, name);
    }


    void bind(){
        glUseProgram(shader);

        num_sampler2D = 0;
        num_samplerCube = 0;
        num_sampler2DArray = 0;
    }

    static void unbind(){
        glUseProgram(0);
    }

    void dispose() const{
        glDeleteProgram(shader);
    }

private:

    static GLuint createProgram(const GLchar *vertexCode, const GLchar *fragmentCode){
        const GLuint shaderID = glCreateProgram();

        const GLuint vertexShaderID = createShader(vertexCode, GL_VERTEX_SHADER);
        const GLuint fragmentShaderID = createShader(fragmentCode, GL_FRAGMENT_SHADER);

        glAttachShader(shaderID, vertexShaderID);
        glAttachShader(shaderID, fragmentShaderID);
        glLinkProgram(shaderID);

        int success;
        glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
        if(!success){
            GLchar infoLog[1024];
            glGetProgramInfoLog(shaderID, 1024, NULL, infoLog);
            cout << "Linking shader error: \n" << infoLog << endl;
        }

        glValidateProgram(shaderID);

        glGetProgramiv(shaderID, GL_VALIDATE_STATUS, &success);
        if(!success){
            GLchar infoLog[1024];
            glGetProgramInfoLog(shaderID, 1024, NULL, infoLog);
            cout << "Validating shader error: \n" << infoLog << endl;
        }

        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);

        return shaderID;
    }

    static GLuint createShader(const GLchar *code, int shaderType){
        const GLuint shaderID = glCreateShader(shaderType);
        glShaderSource(shaderID, 1, &code, nullptr);
        glCompileShader(shaderID);

        int success;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

        if(!success){
            GLchar infoLog[1024];
            glGetShaderInfoLog(shaderID, 1024, nullptr, infoLog);
            std::cout << "Compiling shader error: \n" << infoLog << std::endl;
        }
        return shaderID;
    }

};

#endif