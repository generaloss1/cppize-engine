#include "pize-core/Pize.cpp"
#include "pize-core/context/ContextListener.cpp"

#include "pize-core/graphics/texture/Texture.cpp"
#include "pize-core/graphics/mesh/VertexBuffer.cpp"
#include "pize-core/graphics/mesh/VertexAttr.cpp"
#include "pize-core/graphics/mesh/VertexArray.cpp"
#include "pize-core/graphics/gl/Type.cpp"
#include "pize-core/graphics/util/Shader.cpp"
#include <pize-core/math/vecmath/matrix/Matrix4f.cpp>

using namespace std;

class Game : public ContextListener{
private:

    Texture *texture;
    Shader *shader;
    VertexArray *vao;
    VertexBuffer *vbo;
    Matrix4f *projectionMat;
    Matrix4f *viewMat;

public:

    Game(){
        texture = new Texture("116-0.png");

        vao = new VertexArray();

        vbo = new VertexBuffer();
        vbo->enableAttributes(vector<VertexAttr> { VertexAttr(2, FLOAT), VertexAttr(2, FLOAT), VertexAttr(4, FLOAT) });
        vbo->setData(vector<GLfloat> {
             500, 500,  0, 1,  1, 1, 1, 1,  // 0
             500, 0  ,  0, 0,  1, 1, 1, 1,  // 1
             0  , 0  ,  1, 0,  1, 1, 1, 1,  // 2

             0  , 0  ,  1, 0,  1, 1, 1, 1,  // 2
             0  , 500,  1, 1,  1, 1, 1, 1,  // 3
             500, 500,  0, 1,  1, 1, 1, 1,  // 0
        }, STATIC_DRAW);

        shader = new Shader("shader/shader.vert", "shader/shader.frag");
        shader->putUniform("u_projection");
        shader->putUniform("u_view");
        shader->putUniform("u_texture");

        projectionMat = (new Matrix4f())->toOrthographic(0, 0, 1280, 720);
        viewMat = new Matrix4f();
    }

    void render() override{
        if(Pize.keyboard()->isDown(GLFW_KEY_ESCAPE))
            Pize.exit();

        glClearColor(0.1, 0.1, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        shader->bind();
        shader->setUniform("u_projection", projectionMat);
        shader->setUniform("u_view", viewMat);
        shader->setUniform("u_texture", texture);

        vao->drawArrays(vbo->getVerticesNum());

        cout << "fps: " << Pize.getFps() << endl;
    }

    void resize(int width, int height) override{
        projectionMat->toOrthographic(0, 0, float(width), float(height));
    }

    void dispose() override{
        texture->dispose();
        vao->dispose();
        vbo->dispose();
        shader->dispose();
    }

};

int main(){
    Pize.create("My Window", 1280, 720);
    Pize.run(new Game());

    return 0;
}