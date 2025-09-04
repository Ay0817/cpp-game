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
	/// @brief �R���X�g���N�^
	NODISCARD_CPP20 CanvasRenderer(std::weak_ptr<GameObject> owner);

	/// @brief �f�X�g���N�^
	virtual ~CanvasRenderer() noexcept = default;

	// @brief �`��
	virtual void Render() const override;

	/// @brief Canvas ���擾
	/// @return Canvas
	NODISCARD const std::shared_ptr<Canvas>& GetCanvas() const {
		return canvas;
	}

	/// @brief Canvas ��ݒ�
	/// @param newCanvas �V���� Canvas
	void SetCanvas(std::shared_ptr<Canvas>& newCanvas) {
		canvas = std::move(newCanvas);
	}
};

#endif 
