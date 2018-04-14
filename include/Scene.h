#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>

class Renderer;

class Scene {
public:
    enum class Type {
        GameScene
    };
    Scene(Type type) : m_type(type) {}
    virtual ~Scene() {}
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void handleEvents(const SDL_Event& event) = 0;
    virtual void update(float dt) = 0;
    virtual void render(const Renderer& renderer) const = 0;
    Type getType() const {
        return m_type;
    }

private:
    Type m_type;
};

#endif /* SCENE_H */
