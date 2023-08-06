#ifndef PIZE_CORE_IO_WINDOW
#define PIZE_CORE_IO_WINDOW

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "pize-core/io/window/Resizable.cpp"

using namespace std;

class Window{

    GLFWwindow* window;
    const char* title;
    int width, height, x, y;
    bool resizable, focused;
public:
    Resizable* resizeCallback;

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

        window = glfwCreateWindow(width, height, title, NULL, NULL);
        if(window == NULL){
            cout << "Failed to create GLFW window" << endl;
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(vsync ? 1 : 0);

        glfwSetWindowUserPointer(window, this);
        glfwSetWindowFocusCallback(window, staticFocusCallback);
        glfwSetWindowSizeCallback(window, staticSizeCallback);
        glfwSetWindowPosCallback(window, staticPosCallback);

        if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
            cout << "Failed to initialize GLAD" << endl;
            glfwTerminate();
            return;
        }
    }


    bool shouldClose(){
        return glfwWindowShouldClose(window);
    }

    void swapBuffers(){
        glfwSwapBuffers(window);
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
        glfwShowWindow(window);
    }

    void hide(){
        glfwHideWindow(window);
    }


    void registerResizeCallback(Resizable *resizeCallback){
        this->resizeCallback = resizeCallback;
    }


    GLFWwindow *getWindowID(){
        return window;
    }

    void dispose(){
        glfwDestroyWindow(window);
    }

private:

    void sizeCallback(int width, int height){
        this->width = width;
        this->height = height;
        resizeCallback->resize(width, height);
    }

    static void staticFocusCallback(GLFWwindow* window, int focused){
        auto* handler = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if(handler)
            handler->focused = focused == 1;
    }

    static void staticSizeCallback(GLFWwindow* window, int width, int height){
        auto* handler = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if(handler)
            handler->sizeCallback(width, height);
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