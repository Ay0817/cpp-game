#ifndef BEHAVIOUR_HPP
#define BEHAVIOUR_HPP

#include <functional>

#include "Component.hpp"
#include "GameObjectManager.hpp"

class Behaviour : public Component {
private:
	bool awake = false;
	bool begin = false;
protected:
	bool enable = true;
	bool prevEnable = false;
public:
	// @brief コンストラクタ
	NODISCARD_CPP20 Behaviour() = default;

	// @brief コンストラクタ
	NODISCARD_CPP20 Behaviour(std::weak_ptr<GameObject> owner);

	// @brief デストラクタ
	virtual ~Behaviour();

	// @brief インスタンス生成後に呼ばれる処理
	virtual void Awake() {}

	// @brief Update 前に1度だけ呼ばれる処理
	virtual void Begin() {}

	// @brief 更新処理
	virtual void Update(float deltaTime) {}

	// @brief 更新処理
	virtual void FixedUpdate(float deltaTime) {}

	// @brief 更新処理
	virtual void LateUpdate(float deltaTime) {}

	// @brief 終了処理
	virtual void End() {}

	// @brief オブジェクトが有効になった時に呼び出される
	virtual void OnEnable() {}

	// @brief オブジェクトが無効になった時に呼び出される
	virtual void OnDisable() {}

	// @brief 設定した時間（単位は秒）後に関数を呼び出します
	void Invoke(std::function<void()> func, float sec);

	// @brief 設定した時間（単位は秒）後に関数を呼び出し、 repeatRate 秒ごとにリピートします
	void InvokeRepeating(std::function<void()> func, float sec, float repeatRate);

	// @brief Behaviour の状態をセットする
	void SetEnable(bool state) {
		enable = state;
	}

	// @brief Behaviour の状態を取得する
	NODISCARD bool GetEnable() const {
		return enable;
	}

	// @brief Awake がすでに呼び出されたか?
	NODISCARD bool GetAwakeState() const {
		return awake;
	}

	// @brief Awake の呼び出し状態をセット
	void SetAwakeState(bool state) {
		awake = state;
	}

	// @brief Begin がすでに呼び出されたか?
	NODISCARD bool GetBeginState() const {
		return begin;
	}

	// @brief Begin の呼び出し状態をセット
	void SetBeginState(bool state) {
		begin = state;
	}

	// @brief Behaviour の状態を監視と更新を行う
	void UpdateEnableState();
};

#endif
