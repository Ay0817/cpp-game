#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "ImGui/imgui_impl_dx11.h"

namespace Graphics {
	/// @brief 垂直同期を使用するか?
	/// @param state true なら使用、 false なら使用しない
	void SetVsyncEnabled(bool state);

	/// @brief ウィンドウが非アクティブでなくても処理を継続するか?
	/// @param state true なら続行、 false なら続行しない
	void SetAlwaysRun(bool state);

	/// @brief 使用中の ID3D11Device オブジェクトを取得
	/// @return Direct3DDevice11 オブジェクト
	[[nodiscard]] ID3D11Device* GetDirect3D11Device();

	/// @brief 使用中の ID3D11DeviceContext オブジェクトを取得
	/// @return ID3D11DeviceContext オブジェクト
	[[nodiscard]] ID3D11DeviceContext* GetDirect3D11DeviceContext();
}

#endif 
