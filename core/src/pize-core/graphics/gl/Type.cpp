#ifndef PIZE_CORE_GRAPHICS_GL_TYPE
#define PIZE_CORE_GRAPHICS_GL_TYPE

#include "glad/glad.h"
#include "map"

enum Type{
    FLOAT                        = GL_FLOAT                       ,   // 4 Bytes
    INT                          = GL_INT                         ,   // 4 Bytes
    UNSIGNED_INT                 = GL_UNSIGNED_INT                ,   // 4 Bytes
    HALF_FLOAT                   = GL_HALF_FLOAT                  ,   // 2 Bytes
    SHORT                        = GL_SHORT                       ,   // 2 Bytes
    UNSIGNED_SHORT               = GL_UNSIGNED_SHORT              ,   // 2 Bytes
    BOOL                         = GL_BOOL                        ,   // 1 Byte
    BYTE                         = GL_BYTE                        ,   // 1 Byte
    UNSIGNED_BYTE                = GL_UNSIGNED_BYTE               ,   // 1 Byte
    DOUBLE                       = GL_DOUBLE                      ,   // 8 Bytes

    FIXED                        = GL_FIXED                       ,   // 4 Bytes
    INT_2_10_10_10_REV           = GL_INT_2_10_10_10_REV          ,   // 4 Bytes
    UNSIGNED_INT_2_10_10_10_REV  = GL_UNSIGNED_INT_2_10_10_10_REV ,   // 4 Bytes
    UNSIGNED_INT_10F_11F_11F_REV = GL_UNSIGNED_INT_10F_11F_11F_REV    // 4 Bytes
};

static map<Type, char> sizeMap = {
    {FLOAT                       , 4},
    {INT                         , 4},
    {UNSIGNED_INT                , 4},
    {HALF_FLOAT                  , 2},
    {SHORT                       , 2},
    {UNSIGNED_SHORT              , 2},
    {BOOL                        , 1},
    {BYTE                        , 1},
    {UNSIGNED_BYTE               , 1},
    {DOUBLE                      , 8},
    {FIXED                       , 4},
    {INT_2_10_10_10_REV          , 4},
    {UNSIGNED_INT_2_10_10_10_REV , 4},
    {UNSIGNED_INT_10F_11F_11F_REV, 4}
};

static char sizeofType(const Type *type){
    return sizeMap[*type];
}

#endif