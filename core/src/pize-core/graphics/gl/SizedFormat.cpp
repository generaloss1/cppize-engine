#ifndef PIZE_CORE_GRAPHICS_GL_SIZED_FORMAT
#define PIZE_CORE_GRAPHICS_GL_SIZED_FORMAT

#include "glad/glad.h"

enum SizedFormat{

    // <COLOR>
    //     RED
    R8	           = GL_R8	           ,
    R8_SNORM	   = GL_R8_SNORM	   ,
    R16	           = GL_R16	           ,
    R16_SNORM      = GL_R16_SNORM	   ,
    R8I	           = GL_R8I	           ,
    R8UI	       = GL_R8UI	       ,
    R16I	       = GL_R16I	       ,
    R16UI	       = GL_R16UI	       ,
    R32I	       = GL_R32I	       ,
    R32UI	       = GL_R32UI	       ,
    R16F	       = GL_R16F	       ,
    R32F	       = GL_R32F	       ,
    //     RG
    RG8	           = GL_RG8	           ,
    RG8_SNORM      = GL_RG8_SNORM	   ,
    RG16	       = GL_RG16	       ,
    RG16_SNORM     = GL_RG16_SNORM	   ,
    RG16F	       = GL_RG16F	       ,
    RG32F	       = GL_RG32F	       ,
    RG8I	       = GL_RG8I	       ,
    RG8UI	       = GL_RG8UI	       ,
    RG16I	       = GL_RG16I	       ,
    RG16UI	       = GL_RG16UI	       ,
    RG32I	       = GL_RG32I	       ,
    RG32UI	       = GL_RG32UI	       ,
    //     RGB
    R3_G3_B2	   = GL_R3_G3_B2	   ,
    RGB4	       = GL_RGB4	       ,
    RGB5	       = GL_RGB5	       ,
    RGB8	       = GL_RGB8	       ,
    RGB8_SNORM     = GL_RGB8_SNORM	   ,
    RGB10	       = GL_RGB10	       ,
    RGB12	       = GL_RGB12	       ,
    RGB16	       = GL_RGB16	       ,
    RGB16_SNORM    = GL_RGB16_SNORM    ,
    SRGB8	       = GL_SRGB8	       ,
    RGB16F	       = GL_RGB16F	       ,
    RGB32F	       = GL_RGB32F	       ,
    R11F_G11F_B10F = GL_R11F_G11F_B10F ,
    RGB9_E5	       = GL_RGB9_E5	       ,
    RGB8I	       = GL_RGB8I	       ,
    RGB8UI	       = GL_RGB8UI	       ,
    RGB16I	       = GL_RGB16I	       ,
    RGB16UI	       = GL_RGB16UI	       ,
    RGB32I	       = GL_RGB32I	       ,
    RGB32UI	       = GL_RGB32UI	       ,
    RGB10_A2UI     = GL_RGB10_A2UI     ,
    //     RGBA
    RGBA2	       = GL_RGBA2	     ,
    RGBA4	       = GL_RGBA4	     ,
    RGB5_A1	       = GL_RGB5_A1	     ,
    RGBA8	       = GL_RGBA8	     ,
    RGBA8_SNORM    = GL_RGBA8_SNORM  ,
    RGB10_A2       = GL_RGB10_A2 	 ,
    RGBA12	       = GL_RGBA12	     ,
    RGBA16	       = GL_RGBA16	     ,
    RGBA16_SNORM   = GL_RGBA16_SNORM ,
    SRGB8_ALPHA8   = GL_SRGB8_ALPHA8 ,
    RGBA16F	       = GL_RGBA16F	     ,
    RGBA32F	       = GL_RGBA32F	     ,
    RGBA8I	       = GL_RGBA8I	     ,
    RGBA8UI	       = GL_RGBA8UI	     ,
    RGBA16I	       = GL_RGBA16I	     ,
    RGBA16UI	   = GL_RGBA16UI	 ,
    RGBA32I	       = GL_RGBA32I	     ,
    RGBA32UI	   = GL_RGBA32UI	 ,


    // <DEPTH AND STENCIL>
    //     DEPTH_COMPONENT
    DEPTH_COMPONENT16  = GL_DEPTH_COMPONENT16 ,
    DEPTH_COMPONENT24  = GL_DEPTH_COMPONENT24 ,
    DEPTH_COMPONENT32  = GL_DEPTH_COMPONENT32 ,
    DEPTH_COMPONENT32F = GL_DEPTH_COMPONENT32F,
    //     DEPTH_STENCIL
    DEPTH24_STENCIL8   = GL_DEPTH24_STENCIL8  ,
    DEPTH32F_STENCIL8  = GL_DEPTH32F_STENCIL8 ,


    // <COMPRESSED>
    //     RED
    COMPRESSED_RED	                   = GL_COMPRESSED_RED	                   ,
    COMPRESSED_RED_RGTC1	           = GL_COMPRESSED_RED_RGTC1	           ,
    COMPRESSED_SIGNED_RED_RGTC1        = GL_COMPRESSED_SIGNED_RED_RGTC1        ,
    //     RG
    COMPRESSED_RG	                   = GL_COMPRESSED_RG	                   ,
    COMPRESSED_RG_RGTC2	               = GL_COMPRESSED_RG_RGTC2	               ,
    COMPRESSED_SIGNED_RG_RGTC2         = GL_COMPRESSED_SIGNED_RG_RGTC2         ,
    //     RGB
    COMPRESSED_RGB	                   = GL_COMPRESSED_RGB	                   ,
    COMPRESSED_RGB_BPTC_SIGNED_FLOAT   = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT   ,
    COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT ,
    COMPRESSED_SRGB	                   = GL_COMPRESSED_SRGB	                   ,
    //     RGBA
    COMPRESSED_RGBA	                   = GL_COMPRESSED_RGBA	                   ,
    COMPRESSED_RGBA_BPTC_UNORM         = GL_COMPRESSED_RGBA_BPTC_UNORM         ,
    COMPRESSED_SRGB_ALPHA              = GL_COMPRESSED_SRGB_ALPHA              ,
    COMPRESSED_SRGB_ALPHA_BPTC_UNORM   = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM

};

#endif