#ifndef TEXTURE_GRID_HPP
#define TEXTURE_GRID_HPP

#include "CppVersion.hpp"

// @brief �摜�� Grid �f�[�^
struct TextureGrid {
	// @brief �摜�̉������ɑ΂��镪����
	int column;

	// @brief �摜�̏c�ɑ΂��镪����
	int row;

	// @brief �������ꂽ�摜��̑傫��
	int width;

	// @brief �������ꂽ�摜��̑傫��
	int height;

	// @brief �R���X�g���N�^
	NODISCARD_CPP20 TextureGrid() = default;

	// @brief �R���X�g���N�^
	NODISCARD_CPP20 TextureGrid(int column, int row, int width, int height)
		: column(column), row(row), width(width), height(height) {
	}

	// @brief �摜�� Grid �f�[�^���Z�b�g
	void SetGridData(int newColumn, int newRow, int newWidth, int newHeight) {
		column = newColumn;
		row = newRow;
		width = newWidth;
		height = newHeight;
	}

	// @brief �摜�� Grid �f�[�^���Z�b�g
	void SetGridData(const TextureGrid& grid) {
		column = grid.column;
		row    = grid.row;
		width  = grid.width;
		height = grid.height;
	}
};

#endif 
