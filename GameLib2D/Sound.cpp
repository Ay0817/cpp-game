#include <DxLib.h>

#include "Sound.hpp"
#include "Logger.hpp"

Asset::Sound::Sound(std::string_view name, std::string_view path, int handle) : Asset(name, path, handle) {
}

void Asset::Sound::Release() {
	if (handle != -1) {
		DeleteSoundMem(handle);

		Logger::Log("�T�E���h��[" + name + "]���폜����܂����B");
	}
}
