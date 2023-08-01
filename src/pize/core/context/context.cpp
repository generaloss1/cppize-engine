#ifndef CORE_CONTEXT_CONTEXT
#define CORE_CONTEXT_CONTEXT

#include "pize/core/context/context_listener.cpp"
#include "pize/core/io/keyboard.cpp"
#include "pize/core/io/window.cpp"

using namespace std;

class Context{
private:

    Window *window;
    Keyboard *keyboard;
    bool exitRequest;

public:

    Context(const char *title, int width, int height){
        this->window = new Window(title, width, height, true, true, 1);
        this->keyboard = new Keyboard(window);
        this->exitRequest = false;
    }

    void run(ContextListener *listener){
        listener->init();

        window->show();

        while(!window->shouldClose() && !exitRequest){
            glfwPollEvents();

            listener->render();

            keyboard->reset();
            window->swapBuffers();
        }

        window->hide();
        listener->dispose();
        window->dispose();

        glfwTerminate();
    }

    void exit(){
        exitRequest = true;
    }


    Keyboard *getKeyboard(){
        return keyboard;
    }

    Window *getWindow(){
        return window;
    }

};

#endif