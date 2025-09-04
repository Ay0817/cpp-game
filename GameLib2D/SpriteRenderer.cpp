#include "SpriteRenderer.hpp"
#include "Sprite.hpp"
#include "GameObject.hpp"
#include "DxLap.hpp"
#include "RenderSystem.hpp"

SpriteRenderer::SpriteRenderer(std::weak_ptr<GameObject> owner) : Renderer(owner) {
}

void SpriteRenderer::Render() const {
	if (!sprite) return;

	if (auto obj = gameObject.lock()) {
		DxLap::draw_sprite(obj->transform, sprite);
	}
}
