#include <ranges>

#include "InputManager.hpp"

NODISCARD InputManager::State InputManager::next_state(State current, bool pressd) const noexcept {
	if (pressd) {
		return current == State::RELEASE ? State::PRESSING :
			current == State::PRESSING ? State::PRESS :
			current;
	}
	else {
		return (current == State::PRESS || current == State::PRESSING)
			? State::RELEASING
			: State::RELEASE;
	}
}

void InputManager::Update() {
	char buf[256];
	GetHitKeyStateAll(buf);

	for (auto i : std::views::iota(0, 256)) {
		keyInputs[i] = next_state(keyInputs[i], buf[i]);
	}

	auto input = GetMouseInput();
	int mx, my;
	GetMousePoint(&mx, &my);

	auto newPos = Vector2(mx, my);
	delta = newPos - position;
	position = newPos;

	for (auto i : std::views::iota(0, static_cast<int>(mouseInputs.size()))) {
		mouseInputs[i] = next_state(mouseInputs[i], input & (1 << i));
	}
}
