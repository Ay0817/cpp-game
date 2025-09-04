#include <DxLib.h>

#include "Window.hpp"

void Window::SetResolution(Resolution newResolution, bool fullscreen) {
	DxLib::SetGraphMode(static_cast<int>(resolutionMap[newResolution].first), static_cast<int>(resolutionMap[newResolution].second), 32);
	DxLib::ChangeWindowMode(!fullscreen);

	resolution = newResolution;
}

void Window::SetWindowTitle(const std::string& title) {
	DxLib::SetMainWindowClassName(title.data());
	DxLib::SetWindowTextDX(title.data());
}

void Window::SetWindowTitle(std::string_view title) {
	DxLib::SetMainWindowClassName(title.data());
	DxLib::SetWindowTextDX(title.data());
}

void Window::SetWindowTitle(const char* title) {
	DxLib::SetMainWindowClassName(title);
	DxLib::SetWindowTextDX(title);
}

void Window::SetWindowSizeExtendRate(double rate) {
	DxLib::SetWindowSizeExtendRate(rate);
}

void Window::SetWindowSizeChangeEnable(bool state) {
	DxLib::SetWindowSizeChangeEnableFlag(state);
}

void Window::SetWindowBackGroundColor(const Color& color) {
	DxLib::SetBackgroundColor(color.r, color.g, color.b, color.a);
}

void Window::SetWindowStyle(Style style) {
	DxLib::SetWindowStyleMode(std::to_underlying(style));
}

void Window::SetMouseDisplay(bool state) {
	DxLib::SetMouseDispFlag(state);
}

[[nodiscard]] HWND Window::GetWindowHandle() {
	return DxLib::GetMainWindowHandle();
}
