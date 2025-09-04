#include <DxLib.h>

#include "Text.hpp"

Text::Text(std::weak_ptr<GameObject> owner)
	: Behaviour(owner) {
}

void Text::Begin() {
	if (!font) {
		Logger::LogError("�t�H���g�̎擾�Ɏ��s���܂����B");
		return;
	}

	size.first  = GetDrawStringWidthToHandle(text.data(), static_cast<int>(text.length()), font->GetHandle());
	size.second = GetFontSizeToHandle(font->GetHandle());
}
