#ifndef PIZE_CORE_CONTEXT_CONTEXT_LISTENER
#define PIZE_CORE_CONTEXT_CONTEXT_LISTENER

class AppAdapter{
public:

    virtual void render() = 0;
    virtual void resize(int width, int height) = 0;
    virtual void dispose() = 0;

};

#endif
