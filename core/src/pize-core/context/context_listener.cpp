#ifndef CORE_CONTEXT_CONTEXT_LISTENER
#define CORE_CONTEXT_CONTEXT_LISTENER

class ContextListener{
public:

    virtual void init() = 0;
    virtual void render() = 0;
    virtual void resize(int width, int height) = 0;
    virtual void dispose() = 0;

};

#endif
