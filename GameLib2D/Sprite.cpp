#include "Sprite.hpp"
#include "AssetResolver.hpp"

Sprite::Sprite(std::string_view textureName, std::optional<bool> visible) : Object(textureName), visible(visible.value_or(false)) {
	texture = Asset::AssetResolver::GetAsset<Asset::Texture>(textureName);
}

std::shared_ptr<Sprite> Sprite::Create(std::string_view textureName, std::optional<bool> visible) {
	return std::make_shared<Sprite>(textureName, visible.value_or(false));
}
