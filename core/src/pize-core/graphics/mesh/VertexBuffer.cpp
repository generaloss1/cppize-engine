#ifndef PIZE_CORE_GRAPHICS_MESH_VERTEX_BUFFER
#define PIZE_CORE_GRAPHICS_MESH_VERTEX_BUFFER

#include "glad/glad.h"
#include "pize-core/graphics/mesh/VertexAttr.cpp"
#include "pize-core/graphics/gl/BufferUsage.cpp"

class VertexBuffer{
private:

    GLuint buffer;
    int vertexSize, vertexBytes;
    long dataSize;

public:

    VertexBuffer(){
        glGenBuffers(1, &buffer);
        bind();
    }

    void enableAttributes(char attrNum, VertexAttr attributes[]){
        for(char i = 0; i < attrNum; i++){
            VertexAttr attribute = attributes[i];
            vertexSize += attribute.count;
            vertexBytes += attribute.count * sizeofType(&attribute.type);
        }

        int pointer = 0;
        for(char i = 0; i < attrNum; i++){
            const VertexAttr attribute = attributes[i];

            const int count = attribute.count;
            const Type *type = &attribute.type;
            const char typeSize = sizeofType(type);
            cout << "size " << int(i) << " : " << int(typeSize) << endl;

            glVertexAttribPointer(i, count, *type, attribute.normalize, vertexSize * typeSize, &pointer);
            glEnableVertexAttribArray(i);

            pointer += count * typeSize;
        }
    }

    int *getVertexSize(){
        return &vertexSize;
    }

    int *getVertexBytes(){
        return &vertexBytes;
    }

    long *getDataSize(){
        return &dataSize;
    }

    long getVerticesNum(){
        return dataSize / vertexSize;
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


    void setData(float data[], BufferUsage usage){
        dataSize = sizeof(&data) / 4;
        bind();
        glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
    }

    void setData(double data[], BufferUsage usage){
        dataSize = sizeof(&data) / 8;
        bind();
        glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
    }

    void setData(int data[], BufferUsage usage){
        dataSize = sizeof(&data) / 4;
        bind();
        glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
    }

    void setData(short data[], BufferUsage usage){
        dataSize = sizeof(&data) / 2;
        bind();
        glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
    }

    void setData(long data[], BufferUsage usage){
        dataSize = sizeof(&data) / 8;
        bind();
        glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
    }

};

#endif