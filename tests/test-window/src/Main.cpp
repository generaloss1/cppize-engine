#include "iostream"

#include "pize-core/Pize.cpp"
#include "pize-core/context/ContextListener.cpp"

#include "pize-core/graphics/texture/Texture.cpp"
#include "pize-core/graphics/mesh/VertexBuffer.cpp"
#include "pize-core/graphics/mesh/VertexAttr.cpp"
#include "pize-core/graphics/mesh/VertexArray.cpp"

#include "pize-core/graphics/gl/Type.cpp"
#include "pize-core/graphics/gl/BufferUsage.cpp"

using namespace std;

class Game : public ContextListener{
private:

    Texture *texture;
    VertexBuffer *vbo;
    VertexArray *vao;

public:

    Game(){
        texture = new Texture("116-0.png");
        vbo = new VertexBuffer();
        vbo->enableAttributes(2, new VertexAttr[2]{ VertexAttr(2, FLOAT), VertexAttr(4, FLOAT) });
        vao = new VertexArray();

        vbo->setData(new float[]{
            -0.5,  0.5, 1, 0, 0, 1, // 1
            -0.5, -0.5, 0, 1, 1, 1, // 2
             0.5, -0.5, 1, 0, 1, 1, // 3

             0.5, -0.5, 1, 0, 1, 1, // 3
             0.5,  0.5, 0, 0, 1, 1  // 4
            -0.5,  0.5, 1, 0, 0, 1, // 1
        }, STATIC_DRAW);
    }

    void render() override{
        if(Pize.keyboard()->isDown(GLFW_KEY_ESCAPE))
            Pize.exit();

        glClearColor(0.2, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // cout << "fps: " << Pize.getFps() << endl;
    }

    void resize(int width, int height) override{

    }

    void dispose() override{
        texture->dispose();
        vbo->dispose();
        vao->dispose();
    }

};

int main(){
    Pize.create("My Window", 1280, 720);
    Pize.run(new Game());

    return 0;
}