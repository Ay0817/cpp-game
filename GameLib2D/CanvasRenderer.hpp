#ifndef CANVAS_RENDERER_HPP
#define CANVAS_RENDERER_HPP

#include <memory>
#include <vector>

#include "Renderer.hpp"
#include "Canvas.hpp"

/// @brief 
class CanvasRenderer final : public Renderer {
private:
	std::shared_ptr<Canvas> canvas;
public:
	/// @brief コンストラクタ
	NODISCARD_CPP20 CanvasRenderer(std::weak_ptr<GameObject> owner);

	/// @brief デストラクタ
	virtual ~CanvasRenderer() noexcept = default;

	// @brief 描画
	virtual void Render() const override;

	/// @brief Canvas を取得
	/// @return Canvas
	NODISCARD const std::shared_ptr<Canvas>& GetCanvas() const {
		return canvas;
	}

	/// @brief Canvas を設定
	/// @param newCanvas 新たな Canvas
	void SetCanvas(std::shared_ptr<Canvas>& newCanvas) {
		canvas = std::move(newCanvas);
	}
};

#endif 
