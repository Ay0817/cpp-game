//#include "Core.hpp"
//#include "InputManager.hpp"
//#include "GameObjectManager.hpp"
//#include "AssetManager.hpp"
//#include "TimeManager.hpp"
//#include "RenderSystem.hpp"
//#include "FpsController.hpp"
//#include "BehaviourSystem.hpp"
//#include "CursorManager.hpp"
//#include "DxLap.hpp"
//
//#include "../GameEditor/GameEditor.hpp"
//
//bool core::Init() {
//	if (DxLib::DxLib_Init() == -1) {
//		return false;
//	}
//
//	SetDrawScreen(DX_SCREEN_BACK);
//	SetDrawMode(DX_DRAWMODE_BILINEAR);
//
//	//if (!GameEditor::GetInstance().Init()) {
//	//	return false;
//	//}
//
//	TimeManager::Init();
//	FpsController::GetInstance().SetTargetFPS(60.f);
//
//	return true;
//}
//
//void core::Awake() {
//	//BehaviourSystem::GetInstance().Awake();
//}
//
//void core::Begin() {
//	//BehaviourSystem::GetInstance().Begin();
//}
//
//bool core::Loop() {
//	return DxLib::ProcessMessage() != -1;
//}
//
//void core::Update() {
//	//GameObjectManager::GetInstance().OnEnable();
//	//BehaviourSystem::GetInstance().OnEnable();
//	FpsController::GetInstance().BeginFrame();
//	TimeManager::GetInstance().Update();
//	//GameEditor::GetInstance().Update();
//	CursorManager::GetInstance().Update();
//	InputManager::GetInstance().Update();
//	//BehaviourSystem::GetInstance().Update(TimeManager::GetInstance().GetDeltaTime());
//	GameObjectManager::GetInstance().ProcessDestroy();
//	FpsController::GetInstance().EndFrame();
//	//GameObjectManager::GetInstance().OnDisable();
//	//BehaviourSystem::GetInstance().OnDisable();
//}
//
//void core::Render() {
//	DxLib::ClearDrawScreen();
//	RenderSystem::GetInstance().Render();
//	DxLap::draw_fake();
//	//GameEditor::GetInstance().Render();
//	DxLib::ScreenFlip();
//}
//
//void core::End() {
//	//BehaviourSystem::GetInstance().End();
//	Asset::AssetManager::GetInstance().Release();
//	//GameEditor::GetInstance().End();
//	DxLib::DxLib_End();
//}
