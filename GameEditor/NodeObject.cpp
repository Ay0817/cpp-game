#include <ImGuis.hpp>

#include "../GameLib2D/GameObject.hpp"
#include "../GameLib2D/Transform.hpp"
#include "../GameLib2D/Logger.hpp"

#include "NodeObject.hpp"

NodeObject::NodeObject(const std::shared_ptr<GameObject>& obj) : Node(obj->GetName()), object(obj)
{}

void NodeObject::remove_recursively(const std::shared_ptr<NodeObject>& nodeObject) {
	// 子 Node を削除
	if (children.size() > 0) {
		for (auto& child : children) {
			child->remove_recursively(child);
		}
	}
	// 破棄する NodeObject の名前
	auto destroyedName = name;

	// GameObject を破棄
	GameObject::Destroy(destroyedName);

	// 自身を削除
	std::erase(children, nodeObject);

	// ログ出力
	Logger::Log("ノードオブジェクト[" + destroyedName + "]が破棄されました");
}

void NodeObject::Draw() {
	auto obj = object.lock();

	if (!obj) return;

	if (ImGui::TreeNodeEx(name.data(), ImGuiTreeNodeFlags_OpenOnArrow)) {
		if (ImGui::IsItemClicked(0)) {
			onClick.Invoke(obj->GetName());
		}

		if (ImGui::BeginPopupContextItem(name.data())) {
			if (ImGui::MenuItem("Add")) {
				onAddChild.Invoke();
			}
			if (ImGui::MenuItem("Delete")) {
				onDestroy.Invoke();
			}
			ImGui::EndPopup();
		}

		for (auto& child : children) {
			child->Draw();
		}

		ImGui::TreePop();
	}
}

void NodeObject::AddChild(const std::shared_ptr<NodeObject>& nodeObject) {
	children.emplace_back(nodeObject);
}

void NodeObject::RemoveChild(const std::shared_ptr<NodeObject>& nodeObject) {
	remove_recursively(nodeObject);
}
