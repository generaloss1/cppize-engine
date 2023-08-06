#ifndef PIZE_CORE_PIZE
#define PIZE_CORE_PIZE

#include "pize-core/app/Context.cpp"

class Pize{
private:

    Context *ctx;

public:

    void create(const char *title, int width, int height){
        glfwInit();
        ctx = new Context(title, width, height);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    Keyboard *keyboard(){
        return ctx->getKeyboard();
    }

    Window *window(){
        return ctx->getWindow();
    }

    void run(AppAdapter *listener){
        ctx->run(listener);
    }


    void exit(){
        ctx->exit();
    }

    int getFps(){
        return ctx->getFps();
    }

} Pize;

#endif