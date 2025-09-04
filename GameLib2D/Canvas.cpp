#include "Canvas.hpp"

Canvas::Canvas(std::weak_ptr<GameObject> owner)
	: Component(owner) {
}
