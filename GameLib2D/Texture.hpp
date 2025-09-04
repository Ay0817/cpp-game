#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <vector>

#include "Asset.hpp"
#include "TextureGrid.hpp"

namespace Asset {
	// @brief Base class for Texture handling.
	class Texture final : public Asset {
	private:
		int allNum;
		int yNum;
		int xNum;
		std::vector<int> handles;

		std::pair<float, float> size;
	public:
		// @brief �R���X�g���N�^
		NODISCARD_CPP20 Texture(std::string_view name, std::string_view path, int handle, int allNum, int xNum, int yNum, const std::vector<int>& handles = {});

		// @brief �f�X�g���N�^
		virtual ~Texture() = default;

		// @brief ���\�[�X���
		virtual void Release() override;

		// @brief �摜�̕����������擾
		NODISCARD int GetAllNum() const {
			return allNum;
		}

		// @brief �摜�̕����������Z�b�g
		void SetAllNum(int newAllNum) {
			allNum = newAllNum;
		}

		// @brief �摜�̉������ɑ΂��镪�������擾
		NODISCARD int GetNumX() const {
			return xNum;
		}

		// @brief �摜�̉������ɑ΂��镪�������Z�b�g
		void SetNumX(int newNumX) {
			xNum = newNumX;
		}

		// @brief �摜�̏c�ɑ΂��镪�������擾
		NODISCARD int GetNumY() const {
			return yNum;
		}

		// @brief �摜�̏c�ɑ΂��镪�������Z�b�g
		void SetNumY(int newNumY) {
			yNum = newNumY;
		}

		// @brief �摜�̃n���h�����擾
		NODISCARD const std::vector<int> GetHandles() const {
			return handles;
		}

		// @brief �摜�̃n���h�����Z�b�g
		void SetHandles(const std::vector<int>& newHandles) {
			handles = newHandles;
		}

		// @�T�E���h�����Z�b�g
		void SetInfo(std::string_view name, std::string_view path, int handle, int allNum, int xNum, int yNum, const std::vector<int>& handles) {
			SetName(name);
			SetPath(path);
			SetHandle(handle);
			SetAllNum(allNum);
			SetNumX(xNum);
			SetNumY(yNum);
			SetHandles(handles);
		}

		// @brief �摜�̑傫�����擾
		const std::pair<float, float>& GetSize()const {
			return size;
		}

		// @brief �摜�̑傫�����Z�b�g
		void SetSize(float newWidth, float newHeight) {
			size.first = newWidth;
			size.second = newHeight;
		}
	};
}

#endif 
