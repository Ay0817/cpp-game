#include <ranges>

#include "SceneManager.hpp"
#include "Scene.hpp"
#include "SceneBase.hpp"
#include "Logger.hpp"

void SceneManagement::SceneManager::Register(const Scene& scene, std::shared_ptr<SceneBase>& newScene) {
	if (!newScene) {
		Logger::LogError("新規登録を行おうとしたシーン[" + std::string(typeid(newScene).name()) + "]のインスタンスが nullptr でした。");
	}

	sceneMap.emplace(scene.GetHandle(), newScene);
}

//const Scene& SceneManagement::SceneManager::GetSceneByName(std::string_view name) {
//    // TODO: return ステートメントをここに挿入します
//}
//
//const Scene& SceneManagement::SceneManager::GetSceneByIndex(int index) {
//    // TODO: return ステートメントをここに挿入します
//}

bool SceneManagement::SceneManager::SetActiveScene(const Scene& scene) {
	if (auto it = sceneMap.find(scene.GetHandle()); it != sceneMap.end()) {
		currentScene.push(it->second);


		return true;
	}
	return false;
}

void SceneManagement::SceneManager::LoadScene(std::string_view sceneName, LoadSceneMode mode) {

}

void SceneManagement::SceneManager::LoadScene(int index, LoadSceneMode mode) {

}

void SceneManagement::SceneManager::UnloadScene(std::string_view sceneName) {

}

void SceneManagement::SceneManager::UnloadScene(int index) {

}
