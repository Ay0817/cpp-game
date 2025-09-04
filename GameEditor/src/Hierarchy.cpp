#include <typeinfo>
#include <ranges>
#include <ImGuis.hpp>

#include "../GameLib2D/Internal.hpp"
#include "../GameLib2D/GameObject.hpp"

#include "../include/Hierarchy.hpp"
#include "../include/NodeObject.hpp"

Hierarchy::Hierarchy() : rate(1.5f), size(250.f, 400.f), name(internal::string::slicing_for_space(typeid(Hierarchy).name())) {
}

void Hierarchy::request_add(const std::shared_ptr<NodeObject>& nodeObject) {
	toAdd.emplace_back(nodeObject);
}

void Hierarchy::request_destroy(const std::shared_ptr<NodeObject>& nodeObject) {
	toDestroy.emplace_back(nodeObject);
}

bool Hierarchy::set_select_node_recursively(const std::string& name, const std::shared_ptr<NodeObject>& nodeObject) {
	if (nodeObject->GetName() == name) {
		selectNode = nodeObject;
		return true;
	}

	for (auto& child : nodeObject->GetChildren()) {
		set_select_node_recursively(name, child);
		return true;
	}

	return false;
}

void Hierarchy::Draw() const {
	ImGui::SetCursorPosY(90.f);
	ImGui::Text(name.data());
	ImGui::BeginChild(name.data(), size, ImGuiWindowFlags_NoTitleBar);

	for (const auto& nodeObject : nodeObjects) {
		nodeObject->Draw();
	}

	ImGui::EndChild();
}

void Hierarchy::Add(std::shared_ptr<NodeObject> nodeObject) {
	if (!nodeObject) {
		Logger::LogError("nodeObject �̃C���X�^���X�� nullptr �ł��B");
	}

	auto& name = nodeObject->GetName();
	nodeObjects.emplace_back(std::move(nodeObject));

	Logger::Log("�m�[�h�I�u�W�F�N�g["+ name + "]���ǉ�����܂����B");
}

void Hierarchy::AddChild(const std::shared_ptr<NodeObject>& nodeObject) {
	request_add(nodeObject);
}

void Hierarchy::Destroy(const std::shared_ptr<NodeObject>& nodeObject) {
	request_destroy(nodeObject);
}

void Hierarchy::ProcessAdd() {
	for (auto& parentNode : toAdd) {
		auto child   = GameObject::Create("Child", true);
		auto newNode = NodeObject::Create(child);

		Logger::Log("�m�[�h�I�u�W�F�N�g[" + newNode->GetName() + "]���ǉ�����܂����B");

		auto destroy = [this, newNode]() { Destroy(newNode); };
		auto add     = [this, newNode]() { AddChild(newNode); };
		auto click   = [this](const auto& name) { SetSelectNode(name); };
		auto obj     = parentNode->GetGameObject().lock();

		if (!obj) {
			Logger::LogError("GameObject �� nullptr �ł��B");
		}

		child->SetParent(obj);

		newNode->onDestroy  += destroy;
		newNode->onAddChild += add;
		newNode->onClick    += click;

		Logger::Log("�m�[�h�I�u�W�F�N�g[" + newNode->GetName() + "]���m�[�h�I�u�W�F�N�g["+ parentNode->GetName() + "]�̎q�ɓo�^����܂����B");

		parentNode->AddChild(newNode);
	}

	toAdd.clear();
}

void Hierarchy::ProcessDestroy() {
	for (auto& node : toDestroy) {
		auto destroyedName = node->GetName();
		auto& children     = node->GetChildren();
		auto size          = children.size();

		if (size > 0) {
			//TODO: �ċA�I�ɍ폜
			for (auto& child : children) {
				child->RemoveChild(child);
			}
		}

		GameObject::Destroy(destroyedName);

		std::erase(nodeObjects, node);

		Logger::Log("�m�[�h�I�u�W�F�N�g[" + destroyedName + "]���j������܂���");
	}

	toDestroy.clear();
}

void Hierarchy::SetSelectNode(const std::string& name) {
	for (auto& node : nodeObjects) {
		if (set_select_node_recursively(name, node)) {
			return;
		}
	}
}
