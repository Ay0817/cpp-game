#ifndef LOAD_SCENE_MODE_HPP
#define LOAD_SCENE_MODE_HPP

namespace SceneManagement {
	/// @brief �V�[�������[�h����Ƃ��Ɏg�p���܂��B
	enum class LoadSceneMode {
		/// @brief ���݃��[�h����Ă��邷�ׂẴV�[������āA�V�[�������[�h���܂��B
		Single,
		/// @brief ���݃��[�h����Ă���V�[���ɃV�[����ǉ����܂��B
		Additive
	};
}

#endif 
