#include <ImGuis.hpp>

#include "../GameLib2D/GameObject.hpp"
#include "../GameLib2D/Transform.hpp"
#include "../GameLib2D/Logger.hpp"

#include "NodeObject.hpp"

NodeObject::NodeObject(const std::shared_ptr<GameObject>& obj) : Node(obj->GetName()), object(obj)
{}

void NodeObject::remove_recursively(const std::shared_ptr<NodeObject>& nodeObject) {
	// �q Node ���폜
	if (children.size() > 0) {
		for (auto& child : children) {
			child->remove_recursively(child);
		}
	}
	// �j������ NodeObject �̖��O
	auto destroyedName = name;

	// GameObject ��j��
	GameObject::Destroy(destroyedName);

	// ���g���폜
	std::erase(children, nodeObject);

	// ���O�o��
	Logger::Log("�m�[�h�I�u�W�F�N�g[" + destroyedName + "]���j������܂���");
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
