#include <iostream>
#include "pize/core/io/window.cpp"
#include "pize/core/pize.cpp"
#include "pize/core/context/context_listener.cpp"

using namespace std;

class Game : public ContextListener{
public:

    void init() override{

    }

    void render() override{
        if(Pize.keyboard()->isDown(GLFW_KEY_ESCAPE))
            Pize.exit();

        glClearColor(0.2, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void resize(int width, int height) override{

    }

    void dispose() override{

    }

};

int main(){
    Pize.create("My Window", 1280, 720);
    Pize.run(new Game());

    return 0;
}