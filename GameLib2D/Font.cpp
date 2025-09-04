#include <DxLib.h>

#include "Font.hpp"
#include "Logger.hpp"

Asset::Font::Font(std::string_view name, std::string_view path, int handle, int size, int thick, int type) : Asset(name, path, handle) {
	SetInfo(name, path, handle, size, thick, type);
}

void Asset::Font::Release() {
	if (handle != -1) {
		DeleteFontToHandle(handle);
		RemoveFontResourceExA(path.data(), FR_PRIVATE, NULL);

		Logger::Log("フォント名[" + name + "]が削除されました。");
	}
}
