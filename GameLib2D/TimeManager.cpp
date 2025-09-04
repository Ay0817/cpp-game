#include <chrono>

#include "TimeManager.hpp"
#include "Time.hpp"

void TimeManager::Init() {
	auto& instance = GetInstance();

	instance.last      = 0.f;
	instance.timeScale = 1.f;

	instance.now = internal::time::get_now_time();
}

void TimeManager::Update() {
	last = now;
	now = internal::time::get_now_time();
}
