#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include <vector>

/*‘O•ûéŒ¾*/
class GameObject;

namespace SceneManagement {
	/// @brief ƒV[ƒ“î•ñ
	struct Scene {
		/// @brief 
		enum class LodingState {
			NotLoaded,
			Loading,
			Loaded,
			Unloading
		};
	private:
		int handle;
	public:
		std::string name;

		[[nodiscard]] int GetHandle() const noexcept;

		[[nodiscard]] const std::vector<GameObject>& GetRootGameObjects() const;

		[[nodiscard]] bool IsValid() const noexcept;
	};

	namespace internal {
		inline Scene::LodingState lodingState = Scene::LodingState::NotLoaded;
	}
}

#endif
