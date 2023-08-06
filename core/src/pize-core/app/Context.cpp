#ifndef PIZE_CORE_CONTEXT_CONTEXT
#define PIZE_CORE_CONTEXT_CONTEXT

#include <vector>
#include "AppAdapter.cpp"
#include "pize-core/io/Keyboard.cpp"
#include "pize-core/io/window/Window.cpp"
#include "pize-core/util/time/FpsCounter.cpp"

using namespace std;

class Context: Resizable{
private:

    Window *window;
    Keyboard *keyboard;
    bool exitRequest;

    FpsCounter *fpsCounter;

    AppAdapter *listener;

public:

    Context(const char *title, int width, int height){
        this->window = new Window(title, width, height, true, false, 1);

        this->keyboard = new Keyboard(window);
        this->exitRequest = false;

        this->fpsCounter = new FpsCounter();
    }

    void run(AppAdapter *listener){
        this->listener = listener;
        this->window->registerResizeCallback(this);
        window->show();

        while(!window->shouldClose() && !exitRequest)
            render();
        window->hide();
        listener->dispose();

        window->dispose();
        glfwTerminate();
    }

    void render(){
        fpsCounter->count();
        listener->render();

        keyboard->reset();
        window->swapBuffers();
        glfwPollEvents();
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

private:

    void resize(int width, int height) override{
        listener->resize(width, height);
        // glViewport(0, 0, width, height);
    }

};

#endif