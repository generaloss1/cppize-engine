#ifndef PIZE_CORE_IO_WINDOW
#define PIZE_CORE_IO_WINDOW

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

using namespace std;

class Window{

    GLFWwindow *glfwWindow;
    const char *title;
    int width, height, x, y;
    bool resizable, focused;

public:

    Window(const char *title, int width, int height, bool resizable, bool vsync, int samples){
        this->title = title;
        this->width = width;
        this->height = height;
        this->resizable = resizable;

        this->focused = false;
        this->x = 0;
        this->y = 0;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_SAMPLES, samples);

        #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif

        glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
        if(glfwWindow == NULL){
            cout << "Failed to create GLFW window" << endl;
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(glfwWindow);
        glfwSwapInterval(vsync ? 1 : 0);

        glfwSetWindowUserPointer(glfwWindow, this);
        glfwSetWindowFocusCallback(glfwWindow, staticFocusCallback);
        glfwSetWindowSizeCallback(glfwWindow, staticSizeCallback);
        glfwSetWindowPosCallback(glfwWindow, staticPosCallback);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
            cout << "Failed to initialize GLAD" << endl;
            glfwTerminate();
            return;
        }
    }


    bool shouldClose(){
        return glfwWindowShouldClose(glfwWindow);
    }

    void swapBuffers(){
        glfwSwapBuffers(glfwWindow);
    }


    char getTitle(){
        return *title;
    }

    int &getWidth(){
        return width;
    }

    int &getHeight(){
        return height;
    }

    bool &isFocused(){
        return focused;
    }

    bool &isResizable(){
        return resizable;
    }

    void show(){
        glfwShowWindow(glfwWindow);
    }

    void hide(){
        glfwHideWindow(glfwWindow);
    }


    GLFWwindow *getGLFWWindow(){
        return glfwWindow;
    }

    void dispose(){
        glfwDestroyWindow(glfwWindow);
    }

private:

    static void staticFocusCallback(GLFWwindow* window, int focused){
        auto* handler = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if(handler)
            handler->focused = focused == 1;
    }

    static void staticSizeCallback(GLFWwindow* window, int width, int height){
        auto* handler = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if(handler){
            handler->width = width;
            handler->height = height;
        }
    }

    static void staticPosCallback(GLFWwindow* window, int x, int y){
        auto* handler = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if(handler){
            handler->x = x;
            handler->y = y;
        }
    }

};

#endif