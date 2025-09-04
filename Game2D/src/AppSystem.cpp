#include <DxLib.h>
#include <GameLib2D.hpp>

#include "../include/AppSystem.hpp"
#include "../include/Arisu.hpp"

AppSystem::AppSystem()
	: gameEditor(std::make_unique<GameEditor>())
{}

AppSystem::~AppSystem() {
	Asset::AssetManager::GetInstance().Release();
	BehaviourSystem::GetInstance().End();
	gameEditor->End();
	DxLib::DxLib_End();
}

bool AppSystem::Boot() const {
	DxLib::SetUseDirect3DVersion(DX_DIRECT3D_11);
	Graphics::SetAlwaysRun(true);
	Window::SetWindowSizeExtendRate(1.0);
	Window::SetWindowTitle(windowTitle);
	Window::SetResolution(Window::Resolution::HD_1280x720, false);
	Window::SetWindowSizeChangeEnable(true);
	Window::SetWindowStyle(Window::Style::MAX_NORM);
	Window::SetWindowBackGroundColor(Color::black());

	if (DxLib::DxLib_Init() == FAILED) {
		return false;
	}

	DxLib::SetDrawScreen(DX_SCREEN_BACK);
	DxLib::SetDrawMode(DX_DRAWMODE_BILINEAR);

	if (!gameEditor->Init()) {
		return false;
	}

	TimeManager::Init();
	FpsController::GetInstance().SetTargetFPS(TARGET_FPS);

	if (!Init()) {
		return false;
	}

	return true;
}

bool AppSystem::Init() const {
	Asset::FontLoader::Load("Assets/Jsons/Font.json");
	Asset::SoundLoader::Load("Assets/Jsons/Sound.json");
	Asset::TextureLoader::Load("Assets/Jsons/Texture.json");

	Asset::AssetManager::GetInstance().Register<Asset::Font>(Asset::FontManager::GetInstance());
	Asset::AssetManager::GetInstance().Register<Asset::Sound>(Asset::SoundManager::GetInstance());
	Asset::AssetManager::GetInstance().Register<Asset::Texture>(Asset::TextureManager::GetInstance());

	BehaviourSystem::GetInstance().Awake();

	return true;
}

void AppSystem::Run() {
	//auto obj = GameObject::Create("Arisu", "Arisu", 0, true, true);
	//obj->AddComponent<Arisu>();

	//auto canvas = GameObject::Create("Canvas", true);
	//auto obj1 = GameObject::Create("obj1", true);
	//auto obj2 = GameObject::Create("obj2", true);
	//auto obj3 = GameObject::Create("obj3", true);

	//obj1->SetParent(canvas);
	//obj2->SetParent(canvas);
	//obj3->SetParent(canvas);


	while (DxLib::ProcessMessage() != FAILED) {
		BehaviourSystem::GetInstance().Begin();

		FpsController::GetInstance().BeginFrame();
		TimeManager::GetInstance().Update();
		gameEditor->Update();
		CursorManager::GetInstance().Update();
		InputManager::GetInstance().Update();

		BehaviourSystem::GetInstance().Update(Time.GetDeltaTime());
		GameObjectManager::GetInstance().ProcessDestroy();
		FpsController::GetInstance().EndFrame();

		DxLib::ClearDrawScreen();
		RenderSystem::GetInstance().Render();
		gameEditor->Render();
		DxLib::ScreenFlip();
	}
}
