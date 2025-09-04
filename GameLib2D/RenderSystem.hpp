#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include <memory>
#include <vector>

#include "Renderer.hpp"
#include "Config.hpp"

// @brief •`‰æƒVƒXƒeƒ€
class RenderSystem final {
	CLASS_SINGLETON_BODY(RenderSystem)
private:
	std::vector<std::shared_ptr<Renderer>> renderers;
public:
	// @brief “o˜^ˆ—
	void Register(const std::shared_ptr<Renderer>& renderer);

	// @brief •`‰æˆ—
	void Render() const;
};


#endif
