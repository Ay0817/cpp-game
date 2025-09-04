#include <DxLib.h>

#include "DxLap.hpp"

void DxLap::draw_string(const Vector2& pos, const std::string& str, const Color& col) {
	DxLib::DrawStringF(pos.x, pos.y, str.data(), col.ToUInt());

	//TODO: Text class Ç©ÇÁÇÃåƒÇ—èoÇ≥ÇÍÇÈ
}

void DxLap::draw_string(const Vector2& pos, const std::string& str, const Color& col, const std::shared_ptr<Asset::Font>& font) {
	DxLib::DrawStringFToHandle(pos.x, pos.y, str.data(), col.ToUInt(), font->GetHandle());

	//TODO: Text class Ç©ÇÁÇÃåƒÇ—èoÇ≥ÇÍÇÈ
}

void DxLap::play_sound(const std::shared_ptr<Asset::Sound>& sound, int type) {
	DxLib::PlaySoundMem(sound->GetHandle(), type);
}

void DxLap::stop_sound(const std::shared_ptr<Asset::Sound>& sound) {
	DxLib::StopSoundMem(sound->GetHandle());
}

bool DxLap::is_playing(const std::shared_ptr<Asset::Sound>& sound) {
	return DxLib::CheckSoundMem(sound->GetHandle());
}

void DxLap::draw_sprite(const std::shared_ptr<Transform>& transfrom, const std::shared_ptr<Sprite>& sprite) {
	if (!sprite->GetVisible()) return;

	const auto& [x, y] = transfrom->GetPosition();
	const auto& scale = transfrom->GetScale();
	const auto& angle = transfrom->GetAngle();
	const auto& texture = sprite->GetTexture();
	const auto& handle = texture->GetHandle();

	DxLib::DrawRotaGraphF(x, y, scale, angle, handle, true);
}

void DxLap::draw_sprite(const std::shared_ptr<Transform>& transfrom, int handle) {
	const auto& [x, y] = transfrom->GetPosition();
	const auto& scale = transfrom->GetScale();
	const auto& angle = transfrom->GetAngle();

	DxLib::DrawRotaGraphF(x, y, scale, angle, handle, true);
}

void DxLap::draw_fake() {
	DxLib::DrawPixel(1, 1, 0);
}
