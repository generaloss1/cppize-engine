#ifndef PIZE_CORE_GRAPHICS_MESH_VERTEX_ATTRIBUTE
#define PIZE_CORE_GRAPHICS_MESH_VERTEX_ATTRIBUTE

#include "pize-core/graphics/gl/Type.cpp"

struct VertexAttr{ // 12 Bytes

    const int count;      // 4 Bytes
    const Type type;      // 4 Bytes
    const bool normalize; // 1 Byte

    VertexAttr(int count, Type type):
        count(count), type(type), normalize(false){}

    VertexAttr(int count, Type type, bool normalize):
        count(count), type(type), normalize(normalize){}

};

#endif