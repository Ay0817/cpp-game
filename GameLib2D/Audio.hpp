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
	// @brief デフォルトコンストラクタ
	NODISCARD_CPP20 Audio() = default;

	// @brief コンストラクタ
	NODISCARD_CPP20 Audio(std::weak_ptr<GameObject> owner);

	// @brief サウンドタイプをセット
	void SetSoundType(int newType) {
		type = newType;
	}

	// @brief サウンドタイプを取得
	NODISCARD int GetSoundType() const {
		return type;
	}

	// @brief サウンド音量をセット
	// @param newVolume %指定
	void SetVolume(int newVolume) {
		newVolume = math::Clamp(newVolume, 0, 100);
		volume = static_cast<int>(255 * (newVolume / 100.0f));
	}

	// @brief サウンド音量を取得
	NODISCARD int GetVolume() const {
		return volume;
	}

	// @brief Sound インスタンスをセット
	void SetSound(std::shared_ptr<Asset::Sound> newSound) {
		sound = std::move(newSound);
	}

	// @brief Sound インスタンス取得
	NODISCARD std::shared_ptr<Asset::Sound> GetSound() const {
		return sound;
	}

	// @brief 
	void Set(int type, int volume, std::shared_ptr<Asset::Sound> sound) {
		SetSoundType(type);
		SetVolume(volume);
		SetSound(sound);
	}

	// @brief サウンドを再生
	void Play() const;

	// @brief サウンドを停止
	void Stop();

	// @brief 再生中か?
	bool IsPlaying() const;
};

#endif 
