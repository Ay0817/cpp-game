#include <ranges>

#include "SceneManager.hpp"
#include "Scene.hpp"
#include "SceneBase.hpp"
#include "Logger.hpp"

void SceneManagement::SceneManager::Register(const Scene& scene, std::shared_ptr<SceneBase>& newScene) {
	if (!newScene) {
		Logger::LogError("�V�K�o�^���s�����Ƃ����V�[��[" + std::string(typeid(newScene).name()) + "]�̃C���X�^���X�� nullptr �ł����B");
	}

	sceneMap.emplace(scene.GetHandle(), newScene);
}

//const Scene& SceneManagement::SceneManager::GetSceneByName(std::string_view name) {
//    // TODO: return �X�e�[�g�����g�������ɑ}�����܂�
//}
//
//const Scene& SceneManagement::SceneManager::GetSceneByIndex(int index) {
//    // TODO: return �X�e�[�g�����g�������ɑ}�����܂�
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
