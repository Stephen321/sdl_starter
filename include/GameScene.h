#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"

class GameScene : public Scene {
public:
    GameScene();
    void start() override;
    void stop() override;
    void handleEvents(const SDL_Event& event) override;
    void update(float dt) override;
    void render(const Renderer& renderer) const override;

private:
    const Uint8* m_keys;
};

#endif /* GAMESCENE_H */
