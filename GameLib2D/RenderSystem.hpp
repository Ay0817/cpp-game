#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include <memory>
#include <vector>

#include "Renderer.hpp"
#include "Config.hpp"

// @brief �`��V�X�e��
class RenderSystem final {
	CLASS_SINGLETON_BODY(RenderSystem)
private:
	std::vector<std::shared_ptr<Renderer>> renderers;
public:
	// @brief �o�^����
	void Register(const std::shared_ptr<Renderer>& renderer);

	// @brief �`�揈��
	void Render() const;
};


#endif
