#ifndef PIZE_CORE_GRAPHICS_MESH_VERTEX_BUFFER
#define PIZE_CORE_GRAPHICS_MESH_VERTEX_BUFFER

#include "glad/glad.h"
#include "vector"
#include "pize-core/graphics/mesh/VertexAttr.cpp"
#include "pize-core/graphics/gl/BufferUsage.cpp"

class VertexBuffer{
private:

    GLuint buffer;
    int vertexSizeCount, vertexSizeBytes;
    int dataSizeCount;

public:

    VertexBuffer(){
        glGenBuffers(1, &buffer);
        bind();
    }

    void enableAttributes(vector<VertexAttr> attributes){
        vertexSizeCount = 0;
        vertexSizeBytes = 0;

        for(auto attribute: attributes){
            vertexSizeCount += attribute.count;
            vertexSizeBytes += attribute.count * sizeofType(&attribute.type);
        }

        int pointer = 0;
        for(int i = 0; i < attributes.size(); i++){
            const VertexAttr attribute = attributes[i];

            const int count = attribute.count;
            const Type type = attribute.type;
            const char typeSize = sizeofType(&type);

            glVertexAttribPointer(i, count, type, attribute.normalize, vertexSizeCount * typeSize, reinterpret_cast<const void *>(pointer));
            glEnableVertexAttribArray(i);

            pointer += count * typeSize;
        }
    }

    int *getVertexSize(){
        return &vertexSizeCount;
    }

    int *getVertexBytes(){
        return &vertexSizeBytes;
    }

    int *getDataSize(){
        return &dataSizeCount;
    }

    int getVerticesNum() const{
        return dataSizeCount / vertexSizeCount;
    }


    void bind() const{
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
    }

    void dispose(){
        glDeleteBuffers(1, &buffer);
    }

    static void unbind(){
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }


    void setData(const vector<GLfloat>& vertices, BufferUsage usage){
        dataSizeCount = vertices.size();
        bind();
        glBufferData(GL_ARRAY_BUFFER, dataSizeCount * 4, vertices.data(), usage);
    }

    void setData(const vector<GLdouble>& vertices, BufferUsage usage){
        dataSizeCount = vertices.size();
        bind();
        glBufferData(GL_ARRAY_BUFFER, dataSizeCount * 8, vertices.data(), usage);
    }

    void setData(const vector<GLint>& vertices, BufferUsage usage){
        dataSizeCount = vertices.size();
        bind();
        glBufferData(GL_ARRAY_BUFFER, dataSizeCount * 4, vertices.data(), usage);
    }

    void setData(const vector<GLshort>& vertices, BufferUsage usage){
        dataSizeCount = vertices.size();
        bind();
        glBufferData(GL_ARRAY_BUFFER, dataSizeCount * 4, vertices.data(), usage);
    }

};

#endif