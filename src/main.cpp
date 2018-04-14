#include <iostream>

#define SDL_MAIN_HANDLED

#include "SceneManager.h"
#include "Timer.h"


int main(int argc, char* argv[]) {
    SceneManager& sceneManager = SceneManager::getInstance();
    Timer timer;
    while (sceneManager.getRunning()) {
        sceneManager.handleEvents();
        sceneManager.update(timer.getDelta());
        sceneManager.render();
    }
    return 0;
}
