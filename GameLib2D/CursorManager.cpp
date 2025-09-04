#include <DxLib.h>

#include "CursorManager.hpp"
#include "Util.hpp"
#include "Window.hpp"

void CursorManager::Update() {
	if (bind) {
		auto [x, y] = Window::GetWindowCenter();
		SetPosition(Vector2(x, y));
	}
}

const Vector2 CursorManager::GetPosition() const {
	int x, y;
	GetMousePoint(&x, &y);

	return Vector2(x, y);
}

void CursorManager::SetPosition(const Vector2& pos) {
	SetMousePoint(cast(pos.x), cast(pos.y));
}

bool CursorManager::GetVisible() const {
	return visible;
}

void CursorManager::SetVisible(bool state) {
	visible = state;
	Window::SetMouseDisplay(state);
}

void CursorManager::SetCursorLock(bool state) {
	bind = state;
}
