#ifndef PIZE_CORE_CONTEXT_CONTEXT
#define PIZE_CORE_CONTEXT_CONTEXT

#include "ContextListener.cpp"
#include "pize-core/io/Keyboard.cpp"
#include "pize-core/io/Window.cpp"
#include "pize-core/util/time/FpsCounter.cpp"

using namespace std;

class Context{
private:

    Window *window;
    Keyboard *keyboard;
    bool exitRequest;

    FpsCounter *fpsCounter;

public:

    Context(const char *title, int width, int height){
        this->window = new Window(title, width, height, true, true, 1);
        this->keyboard = new Keyboard(window);
        this->exitRequest = false;

        this->fpsCounter = new FpsCounter();
    }

    void run(ContextListener *listener){
        window->show();

        while(!window->shouldClose() && !exitRequest)
            render(listener);

        window->hide();
        listener->dispose();
        window->dispose();

        glfwTerminate();
    }

    void render(ContextListener *listener){
        fpsCounter->count();
        glfwPollEvents();

        listener->render();

        keyboard->reset();
        window->swapBuffers();
    }


    void exit(){
        exitRequest = true;
    }

    int getFps(){
        return fpsCounter->get();
    }


    Keyboard *getKeyboard(){
        return keyboard;
    }

    Window *getWindow(){
        return window;
    }

};

#endif