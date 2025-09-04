#ifndef FONT_HPP
#define FONT_HPP

#include <string>
#include <string_view>

#include "Object.hpp"
#include "Asset.hpp"
#include "CppVersion.hpp"

namespace Asset {
	// @brief �t�H���g�f�[�^�����N���X
	class Font final : public Asset {
	private:
		std::string name;
		std::string path;
		int size;
		int thick;
		int type;
	public:
		// @brief �R���X�g���N�^
		NODISCARD_CPP20 Font(std::string_view name, std::string_view path, int handle, int size, int thick, int type);

		// @brief �f�X�g���N�^
		virtual ~Font() = default;

		// @brief ���\�[�X���
		virtual void Release() override;

		// @brief �T�C�Y��Ԃ�
		NODISCARD int GetSize() const {
			return size;
		}

		// @brief �T�C�Y���Z�b�g
		void SetSize(int newSize) {
			size = newSize;
		}

		// @brief ������Ԃ�
		NODISCARD int GetThick() const {
			return thick;
		}

		// @brief �������Z�b�g
		void SetThick(int newThick) {
			thick = newThick;
		}

		// @brief �^�C�v��Ԃ�
		NODISCARD int GetType() const {
			return type;
		}

		// @brief �^�C�v���Z�b�g
		void SetType(int newType) {
			type = newType;
		}

		// @brief �t�H���g�����Z�b�g
		void SetInfo(std::string_view name, std::string_view path, int handle, int size, int thick, int type) {
			SetName(name);
			SetPath(path);
			SetHandle(handle);
			SetSize(size);
			SetThick(thick);
			SetType(type);
		}
	};
}

#endif
