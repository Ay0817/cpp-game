#include "RenderSystem.hpp"
#include "Util.hpp"
#include "Logger.hpp"
#include "DxLap.hpp"

void RenderSystem::Register(const std::shared_ptr<Renderer>& renderer) {
	auto it = std::lower_bound(
		renderers.begin(),
		renderers.end(),
		renderer, [](const auto& a, const auto& b) {
			return Util::greater(a->GetOrder(), b->GetOrder());
		});

	renderers.insert(it, renderer);

    Logger::Log("RenderSystem ‚É["+ renderer->GetName() + "]‚ª“o˜^‚³‚ê‚Ü‚µ‚½B");
}

void RenderSystem::Render() const {
	for (const auto& renderer : renderers) {
		renderer->Render();
	}
	DxLap::draw_fake();
}
