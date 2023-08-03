#ifndef PIZE_CORE_GRAPHICS_TEXTURE_TEXTURE
#define PIZE_CORE_GRAPHICS_TEXTURE_TEXTURE

#include "pize-core/graphics/texture/Pixmap.cpp"
#include "pize-core/graphics/gl/Format.cpp"
#include "pize-core/graphics/gl/SizedFormat.cpp"
#include "pize-core/graphics/gl/Type.cpp"

using namespace std;

class Texture{
private:

    int minFilter = GL_NEAREST;
    int magFilter = GL_NEAREST;
    int wrapS = GL_CLAMP_TO_BORDER;
    int wrapT = GL_CLAMP_TO_BORDER;
    int wrapR = GL_CLAMP_TO_BORDER;
    int mipmapLevels = 0;
    Format format = RGBA;
    SizedFormat formatSized = RGBA8;
    Type type = UNSIGNED_BYTE;

    Pixmap *pixmap = nullptr;
    GLuint texture = 0;

public:

    explicit Texture(const char *filepath){
        pixmap = new Pixmap(filepath);
        glGenTextures(1, &texture);
        update();
    }

    void dispose(){
        glDeleteTextures(1, &texture);
        pixmap->dispose();
    }

    void bind(){
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    static void unbind(){
        glBindTexture(GL_TEXTURE_2D, 0);
    }

private:

    void update(){
        bind();

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,     minFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,     magFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,         wrapS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,         wrapT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R,         wrapR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL,      mipmapLevels);

        glTexImage2D(
                GL_TEXTURE_2D, 0, formatSized, *pixmap->getWidth(), *pixmap->getHeight(),
                0, format, type, pixmap->getData()
        );

        glGenerateMipmap(GL_TEXTURE_2D);
    }

};

#endif