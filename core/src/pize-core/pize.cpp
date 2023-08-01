#ifndef CORE_PIZE
#define CORE_PIZE

#include "pize-core/context/context.cpp"

class Pize{
private:

    Context *ctx;

public:

    void create(const char *title, int width, int height){
        glfwInit();
        ctx = new Context(title, width, height);
    }


    Keyboard *keyboard(){
        return ctx->getKeyboard();
    }

    Window *window(){
        return ctx->getWindow();
    }


    void run(ContextListener *listener){
        ctx->run(listener);
    }

    void exit(){
        ctx->exit();
    }

} Pize;

#endif