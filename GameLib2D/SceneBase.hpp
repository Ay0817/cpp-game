#ifndef SCENE_BASE_HPP
#define SCENE_BASE_HPP

#include <vector>
#include <memory>
#include <string>
#include <string_view>

#include "CppVersion.hpp"
#include "Scene.hpp"

/*前方宣言*/
class GameObject;

namespace SceneManagement {
	/// @brief シーンの基底クラス。 
/// @brief 新規シーンはこのクラスを継承します。
	class SceneBase {
	private:
		Scene scene;
	protected:
		std::vector<std::shared_ptr<GameObject>> objects;
	public:
		/// @brief コンストラクタ
		NODISCARD_CPP20 constexpr SceneBase() noexcept = default;

		/// @brief コンストラクタ
		/// @param sceneName シーン名
		NODISCARD_CPP20 SceneBase(const Scene& scene);

		/// @brief デストラクタ
		virtual ~SceneBase() = default;

		/// @brief シーンにゲームオブジェクトを追加
		/// @param object 追加するゲームオブジェクトの参照先
		void AddObject(std::shared_ptr<GameObject>& object);

		/// @brief シーンからゲームオブジェクト除外
		/// @param object 除外するゲームオブジェクトの参照先
		void RemoveObject(std::shared_ptr<GameObject>& object);

		/// @brief シーンを取得。
		/// @return シーン
		NODISCARD const Scene& GetScene() const noexcept {
			return scene;
		}
	};
}

#endif 
