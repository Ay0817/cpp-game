#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "ImGui/imgui_impl_dx11.h"

namespace Graphics {
	/// @brief �����������g�p���邩?
	/// @param state true �Ȃ�g�p�A false �Ȃ�g�p���Ȃ�
	void SetVsyncEnabled(bool state);

	/// @brief �E�B���h�E����A�N�e�B�u�łȂ��Ă��������p�����邩?
	/// @param state true �Ȃ瑱�s�A false �Ȃ瑱�s���Ȃ�
	void SetAlwaysRun(bool state);

	/// @brief �g�p���� ID3D11Device �I�u�W�F�N�g���擾
	/// @return Direct3DDevice11 �I�u�W�F�N�g
	[[nodiscard]] ID3D11Device* GetDirect3D11Device();

	/// @brief �g�p���� ID3D11DeviceContext �I�u�W�F�N�g���擾
	/// @return ID3D11DeviceContext �I�u�W�F�N�g
	[[nodiscard]] ID3D11DeviceContext* GetDirect3D11DeviceContext();
}

#endif 
