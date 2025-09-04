#ifndef SCENE_BASE_HPP
#define SCENE_BASE_HPP

#include <vector>
#include <memory>
#include <string>
#include <string_view>

#include "CppVersion.hpp"
#include "Scene.hpp"

/*�O���錾*/
class GameObject;

namespace SceneManagement {
	/// @brief �V�[���̊��N���X�B 
/// @brief �V�K�V�[���͂��̃N���X���p�����܂��B
	class SceneBase {
	private:
		Scene scene;
	protected:
		std::vector<std::shared_ptr<GameObject>> objects;
	public:
		/// @brief �R���X�g���N�^
		NODISCARD_CPP20 constexpr SceneBase() noexcept = default;

		/// @brief �R���X�g���N�^
		/// @param sceneName �V�[����
		NODISCARD_CPP20 SceneBase(const Scene& scene);

		/// @brief �f�X�g���N�^
		virtual ~SceneBase() = default;

		/// @brief �V�[���ɃQ�[���I�u�W�F�N�g��ǉ�
		/// @param object �ǉ�����Q�[���I�u�W�F�N�g�̎Q�Ɛ�
		void AddObject(std::shared_ptr<GameObject>& object);

		/// @brief �V�[������Q�[���I�u�W�F�N�g���O
		/// @param object ���O����Q�[���I�u�W�F�N�g�̎Q�Ɛ�
		void RemoveObject(std::shared_ptr<GameObject>& object);

		/// @brief �V�[�����擾�B
		/// @return �V�[��
		NODISCARD const Scene& GetScene() const noexcept {
			return scene;
		}
	};
}

#endif 
