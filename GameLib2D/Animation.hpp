#ifndef ANIMATION_HPP
#define ANIMATION_HPP

/*
	@file Animation.hpp
	@brief �A�j���[�V�������Đ�
	@author Ay
	@date 2025/08/13
*/

#include <memory>
#include <unordered_map>

#include "Component.hpp"
#include "AnimationClip.hpp"

// @brief Animation �R���|�[�l���g�̓A�j���[�V�������Đ����邽�߂Ɏg�p����܂��B
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
	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Animation(std::weak_ptr<GameObject> owner);

	// @brief �f�X�g���N�^
	virtual ~Animation() noexcept = default;

	// @brief �X�V����
	void Update(float deltaTime);

	// @brief �`�揈��
	void Render() const;

	// @brief �A�j���[�V�������Đ������ǂ����Ԃ�
	NODISCARD bool IsPlaying() const {
		return isPlaying;
	}

	// @brief �A�j���[�V�������Đ������ǂ����Z�b�g����
	void SetPlaying(bool state) {
		isPlaying = state;
	}

	// @brief �A�j���[�V�����N���b�v��ǉ�
	void AddClip(std::shared_ptr<AnimationClip>& clip);

	// @brief �A�j���[�V�������Đ�
	void Play(std::string_view name);

	// @brief �A�j���[�V�������~
	void Stop(std::string_view name);
};

#endif 
