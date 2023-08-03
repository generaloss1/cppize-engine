#ifndef PIZE_CORE_GRAPHICS_MESH_VERTEX_ARRAY
#define PIZE_CORE_GRAPHICS_MESH_VERTEX_ARRAY

#include "glad/glad.h"
#include "pize-core/graphics/gl/Type.cpp"
#include "pize-core/graphics/gl/Primitive.cpp"

class VertexArray{
private:

    GLuint array;

public:

    VertexArray(){
        glGenVertexArrays(1, &array);
        bind();
    }


    void drawArrays(int verticesNum, Primitive mode) const{
        bind();
        glDrawArrays(mode, 0, verticesNum);
    }

    void drawArrays(int verticesNum) const{
        drawArrays(verticesNum, TRIANGLES);
    }


    void drawElements(int indicesNum, Primitive mode, Type indicesType) const{
        bind();
        glDrawElements(mode, indicesNum, indicesType, nullptr);
    }

    void drawElements(int indicesNum, Primitive mode) const{
        drawElements(indicesNum, mode, UNSIGNED_INT);
    }

    void drawElements(int indicesNum) const{
        drawElements(indicesNum, TRIANGLES);
    }


    void bind() const{
        glBindVertexArray(array);
    }

    static void unbind(){
        glBindVertexArray(0);
    }

    void dispose(){
        glDeleteVertexArrays(1, &array);
    }

};

#endif