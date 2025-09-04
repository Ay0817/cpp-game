#include <DxLib.h>
#include <memory>

#include "ParseJson.hpp"
#include "Logger.hpp"

#include "Texture.hpp"
#include "TextureLoader.hpp"
#include "TextureManager.hpp"


void Asset::TextureLoader::Load(const std::string& path) {
	const auto& data = internal::json::parse_from_json<TextureRoot>(path);

	if (!data) {
		Logger::LogError(data.error().custom_error_message);
	}

	for (const auto& item : data.value().items) {
		const auto& name = item.name;
		const auto& path = item.path;
		const auto& allNum = item.allNum;

		if (allNum == 1) {
			auto handle = LoadGraph(path.data());

			if (handle == -1) {
				Logger::LogError("�摜[" + name + "]�̓ǂݍ��݂Ɏ��s���܂����B");
				return;
			}

			const auto& texture = std::make_shared<Texture>(name, path, handle, allNum, 0, 0);
			float w, h;

			if (GetGraphSizeF(handle, &w, &h) == -1) {
				Logger::LogError("�摜�̑傫���̎擾�Ɏ��s���܂����B");
			}

			texture->SetSize(w, h);

			Logger::Log("�摜[" + std::string(name) + "]��ǂݍ��݂܂����B");

			TextureManager::GetInstance().Register(texture);
		}
		else {
			const auto& xNum   = item.xNum;
			const auto& yNum   = item.yNum;
			const auto& width  = item.width;
			const auto& height = item.height;

			std::vector<int> handles;

			LoadDivGraphF(path.data(), allNum, xNum, yNum, width, height, handles.data());

			for (const auto& handle : handles) {
				if (handle == -1) {
					Logger::LogError("�摜[" + name + "]�̓ǂݍ��݂Ɏ��s���܂����B");
					return;
				}
			}

			const auto& texture = std::make_shared<Texture>(name, path, handles.front(), allNum, xNum, yNum, handles);
			texture->SetSize(width, height);

			Logger::Log("�摜[" + std::string(name) + "]��ǂݍ��݂܂����B");

			TextureManager::GetInstance().Register(texture);
		}
	}
}
