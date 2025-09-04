#ifndef ASSET_HPP
#define ASSET_HPP

#include "Object.hpp"
#include "CppVersion.hpp"

namespace Asset {
	// @brief �A�Z�b�g�̊��N���X
	class Asset : public Object {
	protected:
		int handle;
		std::string path;
	public:
		// @brief �R���X�g���N�^
		NODISCARD_CPP20 Asset(std::string_view name, std::string_view path, int handle);

		// @brief �f�X�g���N�^
		virtual ~Asset();

		// @brief �t�@�C���p�X��Ԃ�
		NODISCARD const std::string& GetPath() const {
			return path;
		}

		// @brief �t�@�C���p�X���Z�b�g
		void SetPath(std::string_view newPath) {
			path = newPath;
		}

		// @brief �n���h����Ԃ�
		NODISCARD int GetHandle() const {
			return handle;
		}

		// @brief �n���h�����Z�b�g
		void SetHandle(int newHandle) {
			handle = newHandle;
		}

		// @brief ���\�[�X���
		virtual void Release() {}
	};
}

#endif 
