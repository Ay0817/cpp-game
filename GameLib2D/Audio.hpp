#ifndef AUDIO_HPP
#define AUDIO_HPP

#include "Component.hpp"
#include "Sound.hpp"
#include "Math.hpp"

// @brief 
class Audio : public Component {
protected:
	int type;
	int volume;
	std::shared_ptr<Asset::Sound> sound;
public:
	// @brief �f�t�H���g�R���X�g���N�^
	NODISCARD_CPP20 Audio() = default;

	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Audio(std::weak_ptr<GameObject> owner);

	// @brief �T�E���h�^�C�v���Z�b�g
	void SetSoundType(int newType) {
		type = newType;
	}

	// @brief �T�E���h�^�C�v���擾
	NODISCARD int GetSoundType() const {
		return type;
	}

	// @brief �T�E���h���ʂ��Z�b�g
	// @param newVolume %�w��
	void SetVolume(int newVolume) {
		newVolume = math::Clamp(newVolume, 0, 100);
		volume = static_cast<int>(255 * (newVolume / 100.0f));
	}

	// @brief �T�E���h���ʂ��擾
	NODISCARD int GetVolume() const {
		return volume;
	}

	// @brief Sound �C���X�^���X���Z�b�g
	void SetSound(std::shared_ptr<Asset::Sound> newSound) {
		sound = std::move(newSound);
	}

	// @brief Sound �C���X�^���X�擾
	NODISCARD std::shared_ptr<Asset::Sound> GetSound() const {
		return sound;
	}

	// @brief 
	void Set(int type, int volume, std::shared_ptr<Asset::Sound> sound) {
		SetSoundType(type);
		SetVolume(volume);
		SetSound(sound);
	}

	// @brief �T�E���h���Đ�
	void Play() const;

	// @brief �T�E���h���~
	void Stop();

	// @brief �Đ�����?
	bool IsPlaying() const;
};

#endif 
