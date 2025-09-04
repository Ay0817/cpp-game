#ifndef LOAD_SCENE_MODE_HPP
#define LOAD_SCENE_MODE_HPP

namespace SceneManagement {
	/// @brief シーンをロードするときに使用します。
	enum class LoadSceneMode {
		/// @brief 現在ロードされているすべてのシーンを閉じて、シーンをロードします。
		Single,
		/// @brief 現在ロードされているシーンにシーンを追加します。
		Additive
	};
}

#endif 
