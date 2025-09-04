#include "AnimationClip.hpp"

AnimationClip::AnimationClip(std::string_view name, std::weak_ptr<Sprite> sprite, float frameRate)
	: Object(name), sprite(sprite), frameRate(frameRate) {
}

std::shared_ptr<AnimationClip> AnimationClip::Create(std::string_view name, std::weak_ptr<Sprite> sprite, float frameRate) {
	return std::make_shared<AnimationClip>(name, sprite, frameRate);
}
