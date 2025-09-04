#include "AssetManager.hpp"

void Asset::AssetManager::Release() {
	for (const auto& manager : containerMap) {
		manager.second.Release();
	}
}
