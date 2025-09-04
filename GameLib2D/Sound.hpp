#ifndef SOUND_HPP
#define SOUND_HPP

#include <string>

#include "Object.hpp"
#include "Asset.hpp"
#include "CppVersion.hpp"

namespace Asset {
	// @brief �T�E���h�f�[�^�����N���X
	class Sound : public Asset {
	public:
		// @brief �R���X�g���N�^
		NODISCARD_CPP20 Sound(std::string_view name, std::string_view path, int handle);

		// @brief �f�X�g���N�^
		virtual ~Sound() = default;

		// @brief ���\�[�X���
		virtual void Release() override;

		// @�T�E���h�����Z�b�g
		void SetInfo(std::string_view name, std::string_view path, int handle) {
			SetName(name);
			SetPath(path);
			SetHandle(handle);
		}
	};
}

#endif
