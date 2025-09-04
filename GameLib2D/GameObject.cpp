#include "GameObject.hpp"
#include "GameObjectManager.hpp"
#include "Logger.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include "SpriteRenderer.hpp"
#include "RenderSystem.hpp"
#include "Animation.hpp"
#include "AnimationClip.hpp"

GameObject::GameObject(std::string_view name, std::optional<bool> active) noexcept
	: Object(name), active(active.value_or(false)), tag(""), transform(nullptr) {
}

void GameObject::Init() {
	transform = AddComponent<Transform>();
}

void GameObject::SetParent(const std::shared_ptr<GameObject>& newParent) {
	// 既存の親を外す
	if (auto p = parent.lock()) {
		p->RemoveChild(shared_from_this());
	}

	// 新たな親をセット
	parent = newParent;

	// 自身(子)のtransfromの親をセット
	transform->SetParent(newParent->transform);

	// 親が子を追加する
	newParent->AddChild(shared_from_this());
}

void GameObject::AddChild(const std::shared_ptr<GameObject>& child) {
	// 親が子を追加する追加する
	children.emplace_back(child);

	// 親のtransfromに子のtransfromを追加する
	transform->AddChild(child->transform);

	Logger::Log("ゲームオブジェクト[" + child->GetName() + "]がゲームオブジェクト[" + GetName() + "]の子に登録されました。");
}

void GameObject::RemoveChild(const std::shared_ptr<GameObject>& child) {
	children.erase(std::remove(children.begin(), children.end(), child), children.end());

	Logger::Log("ゲームオブジェクト[" + child->GetName() + "]がゲームオブジェクト[" + GetName() + "]の子から削除されました。");
}

std::shared_ptr<GameObject> GameObject::Create(std::string_view name, std::optional<bool> active) {
	const auto& instance = std::shared_ptr<GameObject>(new GameObject(name, active.value_or(false)));

	instance->Init();

	Logger::Log("ゲームオブジェクト名[" + std::string(name) + "]が生成されました。");

	GameObjectManager::GetInstance().Register(instance);

	return instance;
}

std::shared_ptr<GameObject> GameObject::Create(std::string_view name, std::string_view textureName, int order, std::optional<bool> active, std::optional<bool> visible) {
	const auto& obj = GameObject::Create(name, active);
	auto sprite = Sprite::Create(textureName, visible);
	const auto& spriteRenderer = obj->AddComponent<SpriteRenderer>();

	spriteRenderer->SetOrder(order);
	spriteRenderer->SetSprite(sprite);

	RenderSystem::GetInstance().Register(spriteRenderer);

	return obj;
}

NODISCARD const std::shared_ptr<GameObject> GameObject::Find(const std::string& name) {
	return GameObjectManager::GetInstance().Find(name);
}

NODISCARD void GameObject::Destroy(const std::shared_ptr<Object>& target) {
	return GameObjectManager::GetInstance().Destroy(target);
}

NODISCARD void GameObject::Destroy(const std::string& name) {
	return GameObjectManager::GetInstance().Destroy(name);
}

//std::shared_ptr<GameObject> GameObject::Create(std::string_view name, std::string_view animationName, int order, float frameRate, std::optional<bool> active = std::nullopt, std::optional<bool> visible = std::nullopt) {
//	const auto& obj = Create(name, animationName, order, active, visible);
//
//	auto& sprite = obj->GetComponent<SpriteRenderer>()->GetSprite();
//	auto clip = AnimationClip::Create(animationName, sprite, frameRate);
//	auto animation = obj->AddComponent<Animation>();
//
//	animation->AddClip(clip);
//}
