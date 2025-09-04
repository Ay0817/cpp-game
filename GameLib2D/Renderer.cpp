#include "Renderer.hpp"

Renderer::Renderer(std::weak_ptr<GameObject> owner) 
	: Component(owner) {
}
