#include <ImGuis.hpp>

#include "../GameLib2D/GameObject.hpp"
#include "../GameLib2D/Transform.hpp"
#include "../GameLib2D/Internal.hpp"

#include "../include/Inspector.hpp"

Inspector::Inspector() : rate(3.2f), name(internal::string::slicing_for_space(typeid(Inspector).name())), prevID(0), prevX(0.f), prevY(0.f), prevScale(1.f), prevAngle(0.f) {
	std::memset(x,     0, sizeof(x));
	std::memset(y,     0, sizeof(y));
	std::memset(scale, 0, sizeof(scale));
	std::memset(angle, 0, sizeof(angle));
}

void Inspector::value_update(float x, float y, float scale, float angle, const std::shared_ptr<GameObject>& obj) const {
	// 座標の確認
	if (prevX != x && prevY != y) {
		obj->transform->SetPosition(Vector2(x, y));
	}
	else if (prevX != x) {
		obj->transform->SetPosition(Vector2(x, prevY));
	}
	else if (prevY != y) {
		obj->transform->SetPosition(Vector2(prevX, y));
	}

	// スケールの確認
	if (prevScale != scale) {
		obj->transform->SetScale(scale);
	}

	// 角度の確認
	if (prevAngle != angle) {
		obj->transform->SetAngle(angle);
	}
}

void Inspector::value_setup(const std::shared_ptr<GameObject>& obj) {
	auto id = obj->GetInstanceID();

	if (prevID != id) {
		auto p = obj->transform->GetPosition();
		auto s = obj->transform->GetScale();
		auto a = obj->transform->GetAngle();

		auto strX = std::format("{:.1f}", p.x);
		auto strY = std::format("{:.1f}", p.y);
		auto strS = std::format("{:.2f}", s);
		auto strA = std::format("{:.2f}", a);

		strncpy_s(x    , sizeof(x)    , strX.data(), _TRUNCATE);
		strncpy_s(y    , sizeof(y)    , strY.data(), _TRUNCATE);
		strncpy_s(scale, sizeof(scale), strS.data(), _TRUNCATE);
		strncpy_s(angle, sizeof(angle), strA.data(), _TRUNCATE);

		prevID = id;
	}
}

void Inspector::sanitize_buffer(char* buf) {
	if (buf[0] == '\n') buf[0] = '0';
}

void Inspector::Draw(const std::shared_ptr<GameObject>& obj) {
	value_setup(obj);

	ImGui::SetCursorPosX(ImGui::GetWindowContentRegionMax().x - (ImGui::CalcTextSize(name.data()).x * rate));
	ImGui::SetCursorPosY(90.f);
	ImGui::Text(name.data());

	ImGui::SetCursorPosX(ImGui::GetWindowContentRegionMax().x - (ImGui::CalcTextSize(name.data()).x * rate));
	ImGui::BeginChild(name.data(), ImVec2(200, 400), ImGuiWindowFlags_NoTitleBar);
	ImGui::Text("ObjectName: ");
	ImGui::SameLine();
	ImGui::Text(obj->GetName().data());
	ImGui::InputText("x", x, sizeof(x), ImGuiInputTextFlags_CharsDecimal);
	ImGui::InputText("y", y, sizeof(y), ImGuiInputTextFlags_CharsDecimal);
	ImGui::InputText("scale", scale, sizeof(scale), ImGuiInputTextFlags_CharsDecimal);
	ImGui::InputText("angle", angle, sizeof(angle), ImGuiInputTextFlags_CharsDecimal);
	ImGui::EndChild();

	sanitize_buffer(x);
	sanitize_buffer(y);
	sanitize_buffer(scale);
	sanitize_buffer(angle);

	value_update(std::stof(x), std::stof(y), std::stof(scale), std::stof(angle), obj);
}
