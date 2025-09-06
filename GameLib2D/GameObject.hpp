#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <optional>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <glaze/glaze.hpp>

#include "Object.hpp"
#include "ComponentConcept.hpp"
#include "Logger.hpp"
#include "SubString.hpp"
#include "BehaviourSystem.hpp"

/*--�O���錾--*/
class Transform;
class Behaviour;

// @brief Base class for all objects that can exist in a scene. 
// Add components to a GameObject to control its appearance and behavior.
class GameObject final : public Object, public std::enable_shared_from_this<GameObject> {
private:
	bool active;
	std::string tag;
	std::unordered_map<std::type_index, std::vector<std::shared_ptr<Component>>> componentMap;

	std::weak_ptr<GameObject> parent;
	std::vector<std::shared_ptr<GameObject>> children;

	// @brief �R���X�g���N�^
	GameObject(std::string_view name, std::optional<bool> active = std::nullopt) noexcept;

	// @brief ����������
	void Init();
public:
	std::shared_ptr<Transform> transform;

	// @breif �f�X�g���N�^
	virtual ~GameObject() noexcept = default;

	/// @brief �e�̐ݒ���s���B
	/// @param nweParent �Q�Ɛ�̃Q�[���I�u�W�F�N�g
	void SetParent(const std::shared_ptr<GameObject>& newParent);

	/// @brief �q�̒ǉ����s���B
	/// @param child �Q�Ɛ�̃Q�[���I�u�W�F�N�g
	void AddChild(const std::shared_ptr<GameObject>& child);

	/// @brief �q�̍폜���s���B
	/// @param child  �Q�Ɛ�̃Q�[���I�u�W�F�N�g
	void RemoveChild(const std::shared_ptr<GameObject>& child);

	// @brief �R���|�[�l���g��ǉ�
	template <Concept::is_component T>
	std::shared_ptr<T> AddComponent() {
		auto component = std::make_shared<T>(shared_from_this());
		auto componentName = internal::string::slicing_for_space(typeid(T).name());

		component->SetName(componentName);
		componentMap[typeid(T)].emplace_back(component);

		// ���� Behaviour ���p�����Ă���Ȃ�ABehaviour �Ƃ��Ă��o�^
		if constexpr (std::is_base_of_v<Behaviour, T>) {
			componentMap[typeid(Behaviour)].emplace_back(component);
			BehaviourSys.Register(component);
		}

		Logger::Log("Component[" + component->GetName() + "]���ǉ�����܂����B");

		return component;
	}

	// @brief �R���|�[�l���g���擾
	template <Concept::is_component T>
	NODISCARD std::shared_ptr<T> GetComponent() const {
		auto it = componentMap.find(typeid(T));

		if (it != componentMap.end()) {
			return std::dynamic_pointer_cast<T>(it->second.front());
		}

		Logger::LogError("Component[" + std::string(typeid(T).name()) + "]�̎擾�Ɏ��s���܂����B");

		return nullptr;
	}

	// @brief �R���|�[�l���g���擾
	template <Concept::is_component T>
	NODISCARD const std::vector<std::shared_ptr<T>> GetComponents() const {
		auto it = componentMap.find(typeid(T));

		if (it != componentMap.end()) {
			std::vector<std::shared_ptr<T>> result;

			for (const auto& base : it->second) {
				if (auto casted = std::dynamic_pointer_cast<T>(base)) {
					result.emplace_back(casted);
				}
			}

			return result;
		}

		Logger::LogError("Component[" + internal::string::slicing_for_space(typeid(T).name()) + "]�̎擾�Ɏ��s���܂����B");

		return {};
	}

	/// @brief �e�����R���|�[�l���g���擾
	/// @tparam T �擾������ Component �̌^
	template <Concept::is_component T>
	NODISCARD std::shared_ptr<T> GetComponentInParent() const {
		if (auto obj = parent.lock()) {
			if (auto comp = obj->GetComponent<T>()) {
				return comp;
			}
			if (auto comp = obj->GetComponentInParent<T>()) {
				return comp;
			}
		}
		return nullptr;
	}

	/// @brief �q�����R���|�[�l���g���擾
	/// @tparam T �擾������ Component �̌^
	template <Concept::is_component T>
	NODISCARD std::shared_ptr<T> GetComponentInChildren() const {
		for (const auto& child : children) {
			if (auto comp = child->GetComponent<T>()) {
				return comp;
			}
			if (auto comp = child->GetComponentInChildren<T>()) {
				return comp;
			}
		}
		return nullptr;
	}

	// @brief �^�O��r
	NODISCARD bool CompareTag(const std::string& tag) const {
		return this->tag == tag;
	}

	// @brief �A�N�e�B�u��Ԃ��Z�b�g
	void SetActive(bool state) {
		active = state;
	}

	// @brief �A�N�e�B�u��Ԃ��擾
	NODISCARD bool GetActive() const {
		return active;
	}

	// @brief �Q�[���I�u�W�F�N�g�𐶐�����
	NODISCARD static std::shared_ptr<GameObject> Create(std::string_view name, std::optional<bool> active = std::nullopt);

	// @brief Sprite �Q�[���I�u�W�F�N�g�𐶐�����
	NODISCARD static std::shared_ptr<GameObject> Create(std::string_view name, std::string_view textureName, int order, std::optional<bool> active = std::nullopt, std::optional<bool> visible = std::nullopt);

	// @brief Sprite Animation �Q�[���I�u�W�F�N�g�𐶐�����
	//NODISCARD static std::shared_ptr<GameObject> Create(std::string_view name, std::string_view animationName, int order, float frameRate, std::optional<bool> active = std::nullopt, std::optional<bool> visible = std::nullopt);

	/// @brief 
	/// @param name 
	/// @return 
	NODISCARD static const std::shared_ptr<GameObject> Find(const std::string& name);

	/// @brief 
	/// @param target 
	NODISCARD static void Destroy(const std::shared_ptr<Object>& target);

	/// @brief 
	/// @param name 
	NODISCARD static void Destroy(const std::string& name);

	/// @brief ���J
	friend struct glz::meta<GameObject>;
};

/// @brief ���^�����`
template<>
struct glz::meta<GameObject> {
	static constexpr auto value = object(
		"name"    , &GameObject::name,
		"id"      , &GameObject::instanceID,
		"active"  , &GameObject::active,
		"children", &GameObject::children
	);
};

/// @brief ���[�g
struct GameObjectRoot {
	std::vector<std::shared_ptr<GameObject>> gameObjects;
};

#endif 
