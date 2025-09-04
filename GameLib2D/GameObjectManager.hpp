#ifndef GAME_OBJECT_MANAGER_HPP
#define GAME_OBJECT_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include <string>

#include "Config.hpp"

/*--前方宣言--*/
class GameObject;
class Object;

// @brief 
class GameObjectManager final {
	CLASS_SINGLETON_BODY(GameObjectManager)
private:
	std::unordered_map<unsigned int, std::shared_ptr<GameObject>> objectMap;
	std::vector<unsigned int> toDestroy;
	std::unordered_map<unsigned int, std::shared_ptr<GameObject>> dontDestroyObjectMap;

	// @brief 破棄要求
	void RequestDestroy(const std::string& name);

	// @brief 再帰的に破棄を行う
	void RemoveRecursively(const std::shared_ptr<GameObject>& object);
public:
	// @brief シーン遷移後に呼び出す処理
	void NewSceneInit();

	// @brief Behaviour の状態を監視と更新を行う
	void UpdateEnableState();

	// @brief 登録処理
	void Register(const std::shared_ptr<GameObject>& object);

	// @brief フレームの終わりで破棄
	void ProcessDestroy();

	// @brief シーン遷移時に破棄しないオブジェクトを登録
	void DontDestroy(const std::shared_ptr<GameObject>& object);

	// @brief オブジェクトを破棄
	void Destroy(const std::shared_ptr<Object>& obj);

	// @brief ゲームオブジェクトを破棄
	void Destroy(const std::string& name);

	// @brief ゲームオブジェクトを探す
	NODISCARD const std::shared_ptr<GameObject> Find(const std::string& name) const;

	// @brief 指定したタグを持つゲームオブジェクトを探す
	NODISCARD std::shared_ptr<GameObject> FindWithTag(const std::string& tag) const;

	// @brief 指定したタグを持つゲームオブジェクトを探す
	NODISCARD const std::vector<std::shared_ptr<GameObject>> FindGameObjectsWithTag(const std::string& tag) const;

	// @brief　登録済みのゲームオブジェクトをすべて返す
	NODISCARD const std::vector<std::shared_ptr<GameObject>> RegistedAllObjects() const;
};

#endif
