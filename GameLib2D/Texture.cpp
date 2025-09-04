#include <DxLib.h>

#include "Texture.hpp"
#include "Logger.hpp"

Asset::Texture::Texture(std::string_view name, std::string_view path, int handle, int allNum, int xNum, int yNum, const std::vector<int>& handles)
	: Asset(name, path, -1) {
	SetInfo(name, path, handle, allNum, xNum, yNum, handles);
}

void Asset::Texture::Release() {
	if (allNum > 1) {
		for (const auto& i : handles) {
			if (i != -1) {
				DeleteGraph(i);
			}
		}
		Logger::Log("�摜��[" + name + "]���폜����܂����B");
	}
	else {
		if (handle != -1) {
			DeleteGraph(handle);
			Logger::Log("�摜��[" + name + "]���폜����܂����B");
		}
	}
}
