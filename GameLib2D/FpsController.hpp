#ifndef FPS_CONTROLLER
#define FPS_CONTROLLER

#include "Config.hpp"
#include "Time.hpp"

/// @brief fps ������s���B
class FpsController final {
	CLASS_SINGLETON_BODY(FpsController)
private:
	float fps             = 0.f;
	float deltaTime       = 0.f;
	float targetFPS       = 60.f;
	float targetFrameTime = 1.f / 60.f;

	std::chrono::steady_clock::time_point frameStart;
public:
	/// @brief �t���[�����[�g���w�肷��B
	/// @param targetFPS �Œ肵�����t���[�����[�g�l
	void SetTargetFPS(float fps) {
		targetFPS = fps;
		targetFrameTime = 1.0f / fps;
	}

	/// @brief �t���[���J�n���ɌĂ�
	void BeginFrame() {
		frameStart = std::chrono::steady_clock::now();
	}

	/// @brief �t���[���I�����ɌĂ�
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

	/// @brief ���݂̃t���[�����[�g���擾�B
	/// @return �t���[�����[�g
	NODISCARD float GetFPS() const noexcept {
		return fps;
	}
};

#define FPS FpsController::GetInstance().GetFPS()

#endif 
