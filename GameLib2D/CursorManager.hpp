#ifndef CURSOR_MANAGER_HPP
#define CURSOR_MANAGER_HPP

#include "Config.hpp"
#include "Vector2.hpp"

class CursorManager final {
	CLASS_SINGLETON_BODY(CursorManager)
private:
	bool bind = false;
	bool visible = true;
public:
	/// @brief 更新処理
	void Update();

	/// @brief ウィンドウ上のカーソル座標を取得。
	/// @return カーソル座標
	NODISCARD const Vector2 GetPosition() const;

	/// @brief 指定した座標へカーソルを移動。
	/// @param pos 移動先の座標
	void SetPosition(const Vector2& pos);

	/// @brief カーソルが表示されているか？
	/// @return true 表示されている、 false 表示されていない
	NODISCARD bool GetVisible() const;

	/// @brief カーソルを表示するか？
	/// @param state true なら表示 false なら非表示
	void SetVisible(bool state);

	/// @brief カーソルをウィンドウの中心に固定する。
	/// @param state 
	void SetCursorLock(bool state);
};

#define Cursor CursorManager::GetInstance()

#endif 
