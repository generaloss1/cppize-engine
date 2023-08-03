#ifndef PIZE_CORE_GRAPHICS_GL_FORMAT
#define PIZE_CORE_GRAPHICS_GL_FORMAT

#include "glad/glad.h"

enum Format{
    RED             = GL_RED            ,
    RED_INTEGER     = GL_RED_INTEGER    ,

    RG              = GL_RG             ,
    RG_INTEGER      = GL_RG_INTEGER     ,

    RGB             = GL_RGB            ,
    RGB_INTEGER     = GL_RGB_INTEGER    ,
    BGR             = GL_BGR            ,
    BGR_INTEGER     = GL_BGR_INTEGER    ,

    RGBA            = GL_RGBA           ,
    RGBA_INTEGER    = GL_RGBA_INTEGER   ,
    BGRA            = GL_BGRA           ,
    BGRA_INTEGER    = GL_BGRA_INTEGER   ,

    STENCIL_INDEX   = GL_STENCIL_INDEX  ,
    DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
    DEPTH_STENCIL   = GL_DEPTH_STENCIL
};

#endif