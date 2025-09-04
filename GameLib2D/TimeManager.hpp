#ifndef TIME_MANAGER_HPP
#define TIME_MANAGER_HPP

/// @file TimeManager.hpp
/// @brief 時間処理関係
/// @author Ay
/// @date 2025/8/14

#include "Config.hpp"

/// @brief 時間処理関係クラス
class TimeManager final {
	CLASS_SINGLETON_BODY(TimeManager)
private:
	float now;
	float last;
	float timeScale;
public:
	/// @brief 初期化
	static void Init();

	/// @brief 更新処理
	void Update();

	/// @brief 現在の時間を取得。
	/// @return 現在の時間
	NODISCARD float GetNowTime() const noexcept {
		return now;
	}

	/// @brief 1フレーム前の時間を取得。
	/// @return 1フレーム前の時間
	NODISCARD float GetLastTime() const noexcept {
		return last;
	}

	/// @brief 前フレームからの経過時間を取得。
	/// @return 前フレームから現在のフレームまでの経過時間
	NODISCARD float GetDeltaTime() const noexcept {
		return now - last;
	}

	/// @brief 前フレームからの経過時間にスケールを掛けたデルタタイムを取得。
	/// @return 前フレームから現在フレームまでの経過時間に timeScale を掛けた値
	NODISCARD float GetScaledDeltaTime() const noexcept {
		return (now - last) * timeScale;
	}

	/// @brief ゲーム全体の速度を変更
	/// @param scale 設定する速度
	void SetTimeScale(float scale) noexcept {
		timeScale = scale;
	}
};

#define Time TimeManager::GetInstance()

#endif 
