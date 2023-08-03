#ifndef PIZE_CORE_IO_WINDOW_SIZE_CALLBACK
#define PIZE_CORE_IO_WINDOW_SIZE_CALLBACK

class Resizable{
public:

    virtual void resize(int width, int height) = 0;

};

#endif