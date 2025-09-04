#include <DxLib.h>

#include "Graphics.hpp"

void Graphics::SetVsyncEnabled(bool state) {
	DxLib::SetWaitVSyncFlag(state);
}

void Graphics::SetAlwaysRun(bool state) {
	DxLib::SetAlwaysRunFlag(state);
}

[[nodiscard]] ID3D11Device* Graphics::GetDirect3D11Device() {
	return reinterpret_cast<ID3D11Device*>(const_cast<void*>(DxLib::GetUseDirect3D11Device()));
}

[[nodiscard]] ID3D11DeviceContext* Graphics::GetDirect3D11DeviceContext() {
	return reinterpret_cast<ID3D11DeviceContext*>(const_cast<void*>(DxLib::GetUseDirect3D11DeviceContext()));
}
