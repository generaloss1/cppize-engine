#ifndef PIZE_CORE_IO_KEYBOARD
#define PIZE_CORE_IO_KEYBOARD

#include "pize-core/io/window/Window.cpp"

using namespace std;

class Keyboard{

    static const int KEYS_NUM = GLFW_KEY_LAST + 1; // 349

    bool press[KEYS_NUM];
    bool down[KEYS_NUM];
    bool release[KEYS_NUM];

public:

    Keyboard(Window *window){
        glfwSetWindowUserPointer(window->getWindowID(), this);
        glfwSetKeyCallback(window->getWindowID(), staticKeyCallback);
    }


    bool isPressed(int key){
        return press[key];
    }

    bool isDown(int key){
        return down[key];
    }

    bool isReleased(int key){
        return release[key];
    }


    void reset(){
        for(int i = 0; i < KEYS_NUM; i++){
            release[i] = false;
            down[i] = false;
        }
    }

private:

    void keyCallback(int key, int action){
        if(action == GLFW_PRESS){
            down[key] = true;
            press[key] = true;
        }else if(action == GLFW_RELEASE){
            release[key] = true;
            press[key] = false;
        }
    }

    static void staticKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){
        if(key == -1)
            return;

        auto *handler = reinterpret_cast<Keyboard *>(glfwGetWindowUserPointer(window));
        if(handler)
            handler->keyCallback(key, action);
    }

};

#endif