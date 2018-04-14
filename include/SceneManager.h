#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include "Constants.h"
#include "Renderer.h"
#include "Scene.h"

class SceneManager {
public:
	static SceneManager& getInstance() {
		static SceneManager instance;
		return instance;
	}
	bool getRunning() const;
	void handleEvents();
	void update(float dt);
	void render();
	void changeScene(Scene::Type type);

private:
	SceneManager();
	SceneManager(const SceneManager&) = delete;
	void operator=(const SceneManager&) = delete;
	~SceneManager();

	bool m_running;
	Renderer m_renderer;
	std::vector<Scene*> m_scenes;
	Scene* m_currentScene;
};

#endif /* SCENEMANAGER_H */