#include "CanvasRenderer.hpp"
#include "DxLap.hpp"

CanvasRenderer::CanvasRenderer(std::weak_ptr<GameObject> owner)
	: Renderer(owner) {
}

void CanvasRenderer::Render() const {
	if (!canvas) return;

	// TODO: ç°å„í«â¡
}
