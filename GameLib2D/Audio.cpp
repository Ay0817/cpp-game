#include "Audio.hpp"
#include "SoundType.hpp"
#include "DxLap.hpp"

Audio::Audio(std::weak_ptr<GameObject> owner)
	: Component(owner), type(SoundType::Normal), volume(128){
}

void Audio::Play() const {
	if (!sound) {
		Logger::LogError("sound �C���X�^���X�� null �ł��B");
	}
	DxLap::play_sound(sound, type);
}

void Audio::Stop() {
	if (!sound) {
		Logger::LogError("sound �C���X�^���X�� null �ł��B");
	}
	DxLap::stop_sound(sound);
}

bool Audio::IsPlaying() const {
	if (!sound) {
		Logger::LogError("sound �C���X�^���X�� null �ł��B");
		return false;
	}
	return DxLap::is_playing(sound);
}
