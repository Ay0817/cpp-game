#include "Animation.hpp"
#include "DxLap.hpp"
#include "Util.hpp"

Animation::Animation(std::weak_ptr<GameObject> owner)
	: Component(owner), isPlaying(false) {
}

void Animation::Update(float deltaTime) {
	if (!isPlaying || animationMap.empty()) return;

	currentTime += deltaTime;

	if (currentTime >= frameRate) {
		currentTime = 0.f;
		++currentFrame;
		if (currentFrame > endFrame) {
			currentFrame = startFrame;
		}
	}
}

void Animation::Render() const {
	if (auto obj = gameObject.lock()) {
		DxLap::draw_sprite(obj->transform, handles[currentFrame]);
	}
}

void Animation::AddClip(std::shared_ptr<AnimationClip>& clip) {
	animationMap[clip->GetInstanceID()] = std::move(clip);
}

void Animation::Play(std::string_view name) {
	if (isPlaying) return;

	const auto& animation = animationMap[internal::hash::create_hash_key(name.data())];

	if (!animation) {
		Logger::LogError("アニメーション名[" + animation->GetName() + "]が見つかりませんでした。");
	}

	currentFrame = 0;
	startFrame = 0;
	currentTime = 0.f;

	if (auto sprite = animation->GetSprite().lock()) {
		handles = sprite->GetTexture()->GetHandles();
		endFrame = cast(handles.size());
	}
	else {
		Logger::LogError("Sprite の取得に失敗しました。");
	}
}

void Animation::Stop(std::string_view name) {
	isPlaying = false;
}
