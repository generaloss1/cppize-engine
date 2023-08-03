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


    void drawArrays(int verticesNum, Primitive mode){
        bind();
        glDrawArrays(mode, 0, verticesNum);
    }

    void drawArrays(int verticesNum){
        drawArrays(verticesNum, TRIANGLES);
    }


    void drawElements(int indicesNum, Primitive mode, Type indicesType){
        bind();
        glDrawElements(mode, indicesNum, indicesType, 0);
    }

    void drawElements(int indicesNum, Primitive mode){
        drawElements(indicesNum, mode, UNSIGNED_INT);
    }

    void drawElements(int indicesNum){
        drawElements(indicesNum, TRIANGLES);
    }


    void bind(){
        glBindVertexArray(array);
    }

    void dispose(){
        glDeleteVertexArrays(1, &array);
    }


    static void unbind(){
        glBindVertexArray(0);
    }

};

#endif