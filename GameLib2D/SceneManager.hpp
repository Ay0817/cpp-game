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
	/*前方宣言*/
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

		/// @brief シーンと登録をします。
		/// @param scene 登録を行う新規シーンの参照先。
		void Register(const Scene& scene, std::shared_ptr<SceneBase>& newScene);

		/// @brief シーンの数を取得
		/// @return シーンの数
		NODISCARD int GetSceneCount() const noexcept {
			return sceneCount;
		}

		/// @brief ロード済みのシーンの数を取得
		/// @return ロード済みのシーンの数
		NODISCARD int GetLoadedSceneCount() const noexcept {
			return loadedSceneCount;
		}

		/// @brief シーンをアクティブに設定します。
		/// @param scene 設定するシーン。
		/// @return シーンがまだロードされていない場合は false を返します。
		NODISCARD bool SetActiveScene(const Scene& scene);

		/// @brief ロードされたシーン内で、指定された名前のシーンを検索します。
		/// @param name 検索するシーンの名前。
		/// @return 有効な場合はシーンへの参照が返されます。無効な場合は無効なシーンが返されます。
		NODISCARD const Scene& GetSceneByName(std::string_view name);

		/// @brief ロードされたシーンのリスト内のインデックスにあるシーンを取得します。
		/// @param index 取得するシーンのインデックス。インデックスは0以上、sceneCount 未満である必要があります。
		/// @return 指定されたインデックスのシーンへの参照。
		NODISCARD const Scene& GetSceneByIndex(int index);

		/// @brief 指定された名前のシーンを読み込みます。
		/// @param sceneName ロードするシーンの名前。
		/// @param mode シーンをどのようにロードするかどうかを指定できます。
		void LoadScene(std::string_view sceneName, LoadSceneMode mode = LoadSceneMode::Single);

		/// @brief シーンのリスト内のインデックスにあるシーンを読み込みます。
		/// @param index 取得するシーンのインデックス。インデックスは0以上、sceneCount 未満である必要があります。
		/// @param mode シーンをどのようにロードするかどうかを指定できます。
		void LoadScene(int index, LoadSceneMode mode = LoadSceneMode::Single);

		/// @brief 指定されたシーンに関連付けられたすべてのゲームオブジェクトを破棄し、シーンを SceneManager から削除します。
		/// @param sceneName 削除するシーンの名前。
		void UnloadScene(std::string_view sceneName);

		/// @brief 指定されたシーンに関連付けられたすべてのゲームオブジェクトを破棄し、シーンを SceneManager から削除します。
		/// @param index 削除するシーンのインデックス。
		void UnloadScene(int index);
	};
}

#endif
