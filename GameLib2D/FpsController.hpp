#ifndef FPS_CONTROLLER
#define FPS_CONTROLLER

#include "Config.hpp"
#include "Time.hpp"

/// @brief fps 制御を行う。
class FpsController final {
	CLASS_SINGLETON_BODY(FpsController)
private:
	float fps             = 0.f;
	float deltaTime       = 0.f;
	float targetFPS       = 60.f;
	float targetFrameTime = 1.f / 60.f;

	std::chrono::steady_clock::time_point frameStart;
public:
	/// @brief フレームレートを指定する。
	/// @param targetFPS 固定したいフレームレート値
	void SetTargetFPS(float fps) {
		targetFPS = fps;
		targetFrameTime = 1.0f / fps;
	}

	/// @brief フレーム開始時に呼ぶ
	void BeginFrame() {
		frameStart = std::chrono::steady_clock::now();
	}

	/// @brief フレーム終了時に呼ぶ
	void EndFrame() {
		auto frameEnd = std::chrono::steady_clock::now();
		std::chrono::duration<float> elapsed = frameEnd - frameStart;

		deltaTime = elapsed.count();
		fps = (deltaTime > 0.f) ? (1.f / deltaTime) : 0.f;

		float sleepTime = targetFrameTime - deltaTime;

		if (sleepTime > 0.f) {
			std::this_thread::sleep_for(std::chrono::duration<float>(sleepTime));
			deltaTime = targetFrameTime;
			fps = targetFPS;
		}
	}

	/// @brief 現在のフレームレートを取得。
	/// @return フレームレート
	NODISCARD float GetFPS() const noexcept {
		return fps;
	}
};

#define FPS FpsController::GetInstance().GetFPS()

#endif 
