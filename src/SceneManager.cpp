#include "SceneManager.h"
#include "GameScene.h"

SceneManager::SceneManager()
    : m_running(true) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
        m_running = m_renderer.initialize(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_INPUT_FOCUS);
    else
        m_running = false;

    if (m_running == false) {
        printf("SDL failed to initialize");
    }
    else {
        m_scenes.push_back(new GameScene);

        m_currentScene = m_scenes[0];
        m_currentScene->start();
    }
}

SceneManager::~SceneManager() {
    SDL_Quit();
}

bool SceneManager::getRunning() const {
    return m_running;
}

void SceneManager::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            m_running = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                m_running = false;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        m_currentScene->handleEvents(event);
    }

}

void SceneManager::update(float dt) {
    m_currentScene->update(dt);
}

void SceneManager::render() {
    m_renderer.clear();

    m_renderer.drawRect({ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }, Colour(70, 65, 205, 255));

    m_currentScene->render(m_renderer);

    m_renderer.present();
}

void SceneManager::changeScene(Scene::Type type) {
    for (int i = 0; i < m_scenes.size(); ++i) {
        if (m_scenes[i]->getType() == type) {
            m_currentScene->stop();
            m_currentScene = m_scenes[i];
            m_currentScene->start();
            return;
        }
    }
    printf("No scene of that type could be found.\n");
}
