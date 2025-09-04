#ifndef BEHAVIOUR_SYSTEM_HPP
#define BEHAVIOUR_SYSTEM_HPP

#include <vector>
#include <memory>

#include "Config.hpp"

/*前方宣言*/
class Behaviour;

/// @brief 
class BehaviourSystem final {
	CLASS_SINGLETON_BODY(BehaviourSystem)
private:
	std::vector<std::shared_ptr<Behaviour>> behaviours;
public:
	/// @brief Behaviour を追加する。
	/// @param behaviour 参照先
	void Register(const std::shared_ptr<Behaviour>& behaviour);

	/// @brief インスタンス生成後に呼ばれる処理
	void Awake();

	/// @brief Update 前に1度だけ呼ばれる処理
	void Begin();

	/// @brief 更新処理
	void Update(float deltaTime);

	/// @brief 更新処理
	void FixedUpdate(float deltaTime);

	/// @brief 更新処理
	void LateUpdate(float deltaTime);

	/// @brief 終了処理
	void End();

	/// @brief オブジェクトが有効になった時に呼び出される
	void OnEnable();

	/// @brief オブジェクトが無効になった時に呼び出される
	void OnDisable();
};

#define BehaviourSys BehaviourSystem::GetInstance()

#endif 
