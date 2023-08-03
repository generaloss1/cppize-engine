#ifndef PIZE_CORE_GRAPHICS_TEXTURE_PIXMAP
#define PIZE_CORE_GRAPHICS_TEXTURE_PIXMAP

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class Pixmap{
private:

    unsigned char *data;
    int width, height, channels;

public:

    Pixmap();

    Pixmap(const char *filepath){
        data = stbi_load(filepath, &width, &height, &channels, 0);
        if(!data)
            cout << "Failed to load pixmap '" << filepath << "'" << endl;
        else
            cout << "Loaded pixmap '" << filepath << "'" << endl;
    }

    unsigned char *getData(){
        return data;
    }

    int *getWidth(){
        return &width;
    }

    int *getHeight(){
        return &height;
    }

    int *getChannels(){
        return &channels;
    }

    void dispose(){
        stbi_image_free(&data);
    }

};

#endif