#include <GameLib2D.hpp>

#include "../GameLib2D/ImGui/imgui.h"
#include "../GameLib2D/ImGui/imgui_impl_dx11.h"
#include "../GameLib2D/ImGui/imgui_impl_win32.h"

#include "../include/FrameRate.hpp"
#include "../include/Inspector.hpp"

void FrameRate::Draw() const {
	auto x = ImGui::GetWindowContentRegionMax().x - ImGui::CalcTextSize("FPS: 00.0").x;
	auto y = ImGui::CalcTextSize("F").y * 1.5f;

	ImGui::SetCursorPos(ImVec2(x, y));
	ImGui::Text("FPS:%.1f", FPS);
}
