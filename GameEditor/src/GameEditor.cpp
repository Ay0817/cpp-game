#include <DxLib.h>
#include <GameLib2D.hpp>
#include <ImGuis.hpp>

#include "../include/GameEditor.hpp"
#include "../include/WindowProcess.hpp"
#include "../include/NodeObject.hpp"

bool GameEditor::Init() {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	auto& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.Fonts->AddFontFromFileTTF("C:/my/Fonts/zen-marugothic-main/zen-marugothic-main/fonts/ttf/ZenMaruGothic-Medium.ttf", 23.0f);

	ImGui::StyleColorsDark();
	ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.f, 0.8f, 0.4f, 1.0f));
	auto hwnd = Window::GetWindowHandle();
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX11_Init(Graphics::GetDirect3D11Device(), Graphics::GetDirect3D11DeviceContext());
	SetHookWinProc(WindowProcess);

	hierarchy = std::make_shared<Hierarchy>();
	inspector = std::make_unique<Inspector>();
	frameRate = std::make_unique<FrameRate>();
	addObjectNode = std::make_unique<AddObjectNode>("AddObject", hierarchy);

	return true;
}

void GameEditor::Update() {
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	hierarchy->ProcessAdd();
	hierarchy->ProcessDestroy();
}

void GameEditor::Render() const {
	ImGui::Begin(internal::string::slicing_for_space(typeid(GameEditor).name()).data(), nullptr, ImGuiWindowFlags_NoResize);

	frameRate->Draw();
	hierarchy->Draw();

	if (auto node = hierarchy->GetSelectNode()) {
		if (auto obj = node->GetGameObject().lock()) {
			inspector->Draw(obj);
		}
	}

	addObjectNode->Draw();

	ImGui::End();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}
}

void GameEditor::End() {
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}
