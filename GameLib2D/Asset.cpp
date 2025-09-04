#include "Asset.hpp"

Asset::Asset::Asset(std::string_view name, std::string_view path, int handle)
	: Object(name), path(path), handle(handle) {
}

Asset::Asset::~Asset() {
	Release();
}
