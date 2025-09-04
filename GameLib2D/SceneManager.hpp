#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include <stack>
#include <string>
#include <string_view>

#include "Config.hpp"
#include "Action.hpp"
#include "LoadSceneMode.hpp"

namespace SceneManagement {
	/*�O���錾*/
	class SceneBase;
	struct Scene;

	/// @brief 
	class SceneManager final {
		CLASS_SINGLETON_BODY(SceneManager)
	private:
		int sceneCount = 0;
		int loadedSceneCount = 0;

		std::stack<std::shared_ptr<SceneBase>> currentScene;
		std::unordered_map<int, std::shared_ptr<SceneBase>> sceneMap;
		std::vector<std::shared_ptr<SceneBase>> scenes;
	public:
		static Action<Scene, LoadSceneMode> sceneLoaded;
		static Action<Scene> sceneUnloaded;
		static Action<Scene, Scene> activeSceneChanged;

		/// @brief �V�[���Ɠo�^�����܂��B
		/// @param scene �o�^���s���V�K�V�[���̎Q�Ɛ�B
		void Register(const Scene& scene, std::shared_ptr<SceneBase>& newScene);

		/// @brief �V�[���̐����擾
		/// @return �V�[���̐�
		NODISCARD int GetSceneCount() const noexcept {
			return sceneCount;
		}

		/// @brief ���[�h�ς݂̃V�[���̐����擾
		/// @return ���[�h�ς݂̃V�[���̐�
		NODISCARD int GetLoadedSceneCount() const noexcept {
			return loadedSceneCount;
		}

		/// @brief �V�[�����A�N�e�B�u�ɐݒ肵�܂��B
		/// @param scene �ݒ肷��V�[���B
		/// @return �V�[�����܂����[�h����Ă��Ȃ��ꍇ�� false ��Ԃ��܂��B
		NODISCARD bool SetActiveScene(const Scene& scene);

		/// @brief ���[�h���ꂽ�V�[�����ŁA�w�肳�ꂽ���O�̃V�[�����������܂��B
		/// @param name ��������V�[���̖��O�B
		/// @return �L���ȏꍇ�̓V�[���ւ̎Q�Ƃ��Ԃ���܂��B�����ȏꍇ�͖����ȃV�[�����Ԃ���܂��B
		NODISCARD const Scene& GetSceneByName(std::string_view name);

		/// @brief ���[�h���ꂽ�V�[���̃��X�g���̃C���f�b�N�X�ɂ���V�[�����擾���܂��B
		/// @param index �擾����V�[���̃C���f�b�N�X�B�C���f�b�N�X��0�ȏ�AsceneCount �����ł���K�v������܂��B
		/// @return �w�肳�ꂽ�C���f�b�N�X�̃V�[���ւ̎Q�ƁB
		NODISCARD const Scene& GetSceneByIndex(int index);

		/// @brief �w�肳�ꂽ���O�̃V�[����ǂݍ��݂܂��B
		/// @param sceneName ���[�h����V�[���̖��O�B
		/// @param mode �V�[�����ǂ̂悤�Ƀ��[�h���邩�ǂ������w��ł��܂��B
		void LoadScene(std::string_view sceneName, LoadSceneMode mode = LoadSceneMode::Single);

		/// @brief �V�[���̃��X�g���̃C���f�b�N�X�ɂ���V�[����ǂݍ��݂܂��B
		/// @param index �擾����V�[���̃C���f�b�N�X�B�C���f�b�N�X��0�ȏ�AsceneCount �����ł���K�v������܂��B
		/// @param mode �V�[�����ǂ̂悤�Ƀ��[�h���邩�ǂ������w��ł��܂��B
		void LoadScene(int index, LoadSceneMode mode = LoadSceneMode::Single);

		/// @brief �w�肳�ꂽ�V�[���Ɋ֘A�t����ꂽ���ׂẴQ�[���I�u�W�F�N�g��j�����A�V�[���� SceneManager ����폜���܂��B
		/// @param sceneName �폜����V�[���̖��O�B
		void UnloadScene(std::string_view sceneName);

		/// @brief �w�肳�ꂽ�V�[���Ɋ֘A�t����ꂽ���ׂẴQ�[���I�u�W�F�N�g��j�����A�V�[���� SceneManager ����폜���܂��B
		/// @param index �폜����V�[���̃C���f�b�N�X�B
		void UnloadScene(int index);
	};
}

#endif
