#ifndef ANIMATION_HPP
#define ANIMATION_HPP

/*
	@file Animation.hpp
	@brief アニメーションを再生
	@author Ay
	@date 2025/08/13
*/

#include <memory>
#include <unordered_map>

#include "Component.hpp"
#include "AnimationClip.hpp"

// @brief Animation コンポーネントはアニメーションを再生するために使用されます。
class Animation final : public Component {
private:
	bool isPlaying;
	std::unordered_map<unsigned int, std::shared_ptr<AnimationClip>> animationMap;

	int currentFrame = 0;
	int startFrame   = 0;
	int endFrame     = 0;

	float currentTime = 0.f;
	float frameRate   = 0.f;

	std::vector<int> handles;
public:
	// @brief コンストラクタ
	NODISCARD_CPP20 Animation(std::weak_ptr<GameObject> owner);

	// @brief デストラクタ
	virtual ~Animation() noexcept = default;

	// @brief 更新処理
	void Update(float deltaTime);

	// @brief 描画処理
	void Render() const;

	// @brief アニメーションが再生中かどうか返す
	NODISCARD bool IsPlaying() const {
		return isPlaying;
	}

	// @brief アニメーションが再生中かどうかセットする
	void SetPlaying(bool state) {
		isPlaying = state;
	}

	// @brief アニメーションクリップを追加
	void AddClip(std::shared_ptr<AnimationClip>& clip);

	// @brief アニメーションを再生
	void Play(std::string_view name);

	// @brief アニメーションを停止
	void Stop(std::string_view name);
};

#endif 
