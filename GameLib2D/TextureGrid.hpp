#ifndef TEXTURE_GRID_HPP
#define TEXTURE_GRID_HPP

#include "CppVersion.hpp"

// @brief 画像の Grid データ
struct TextureGrid {
	// @brief 画像の横向きに対する分割数
	int column;

	// @brief 画像の縦に対する分割数
	int row;

	// @brief 分割された画像一つの大きさ
	int width;

	// @brief 分割された画像一つの大きさ
	int height;

	// @brief コンストラクタ
	NODISCARD_CPP20 TextureGrid() = default;

	// @brief コンストラクタ
	NODISCARD_CPP20 TextureGrid(int column, int row, int width, int height)
		: column(column), row(row), width(width), height(height) {
	}

	// @brief 画像の Grid データをセット
	void SetGridData(int newColumn, int newRow, int newWidth, int newHeight) {
		column = newColumn;
		row = newRow;
		width = newWidth;
		height = newHeight;
	}

	// @brief 画像の Grid データをセット
	void SetGridData(const TextureGrid& grid) {
		column = grid.column;
		row    = grid.row;
		width  = grid.width;
		height = grid.height;
	}
};

#endif 
