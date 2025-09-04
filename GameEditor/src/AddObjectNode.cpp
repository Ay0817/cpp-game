#include <ImGuis.hpp>

#include "../GameLib2D/Logger.hpp"
#include "../GameLib2D/GameObject.hpp"

#include "../include/AddObjectNode.hpp"
#include "../include/NodeObject.hpp"

AddObjectNode::AddObjectNode(const std::string& name, const std::shared_ptr<Hierarchy>& hierarchy)
	: Node(name), isActive(false), hierarchy(hierarchy) {
	std::memset(buf, 0, sizeof(buf));
}

void AddObjectNode::Draw() {
	ImGui::SetCursorPosY(ImGui::GetWindowContentRegionMax().y - 145.f);
	if (ImGui::TreeNode(name.data())) {
		ImGui::InputText("Name", buf, sizeof(buf));
		ImGui::Checkbox("Active", &isActive);

		if (ImGui::Button("Register")) {
			auto newObject = GameObject::Create(buf, isActive);

			if (!newObject) {
				Logger::LogError("新規ゲームオブジェクトの生成に失敗しました。");
			}

			auto newNodeObject = NodeObject::Create(newObject);
			auto destroy = [&, newNodeObject]() {hierarchy->Destroy(newNodeObject); };
			auto add     = [&, newNodeObject]() {hierarchy->AddChild(newNodeObject); };
			auto click   = [&](const auto& name) { hierarchy->SetSelectNode(name); };

			newNodeObject->onDestroy  += destroy;
			newNodeObject->onAddChild += add;
			newNodeObject->onClick    += click;

			hierarchy->Add(newNodeObject);

			isActive = false;
			std::fill(std::begin(buf), std::end(buf), '\0');
		}

		ImGui::TreePop();
	}
}
