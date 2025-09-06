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

/*--前方宣言--*/
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

	// @brief コンストラクタ
	GameObject(std::string_view name, std::optional<bool> active = std::nullopt) noexcept;

	// @brief 初期化処理
	void Init();
public:
	std::shared_ptr<Transform> transform;

	// @breif デストラクタ
	virtual ~GameObject() noexcept = default;

	/// @brief 親の設定を行う。
	/// @param nweParent 参照先のゲームオブジェクト
	void SetParent(const std::shared_ptr<GameObject>& newParent);

	/// @brief 子の追加を行う。
	/// @param child 参照先のゲームオブジェクト
	void AddChild(const std::shared_ptr<GameObject>& child);

	/// @brief 子の削除を行う。
	/// @param child  参照先のゲームオブジェクト
	void RemoveChild(const std::shared_ptr<GameObject>& child);

	// @brief コンポーネントを追加
	template <Concept::is_component T>
	std::shared_ptr<T> AddComponent() {
		auto component = std::make_shared<T>(shared_from_this());
		auto componentName = internal::string::slicing_for_space(typeid(T).name());

		component->SetName(componentName);
		componentMap[typeid(T)].emplace_back(component);

		// もし Behaviour を継承しているなら、Behaviour としても登録
		if constexpr (std::is_base_of_v<Behaviour, T>) {
			componentMap[typeid(Behaviour)].emplace_back(component);
			BehaviourSys.Register(component);
		}

		Logger::Log("Component[" + component->GetName() + "]が追加されました。");

		return component;
	}

	// @brief コンポーネントを取得
	template <Concept::is_component T>
	NODISCARD std::shared_ptr<T> GetComponent() const {
		auto it = componentMap.find(typeid(T));

		if (it != componentMap.end()) {
			return std::dynamic_pointer_cast<T>(it->second.front());
		}

		Logger::LogError("Component[" + std::string(typeid(T).name()) + "]の取得に失敗しました。");

		return nullptr;
	}

	// @brief コンポーネントを取得
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

		Logger::LogError("Component[" + internal::string::slicing_for_space(typeid(T).name()) + "]の取得に失敗しました。");

		return {};
	}

	/// @brief 親が持つコンポーネントを取得
	/// @tparam T 取得したい Component の型
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

	/// @brief 子が持つコンポーネントを取得
	/// @tparam T 取得したい Component の型
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

	// @brief タグ比較
	NODISCARD bool CompareTag(const std::string& tag) const {
		return this->tag == tag;
	}

	// @brief アクティブ状態をセット
	void SetActive(bool state) {
		active = state;
	}

	// @brief アクティブ状態を取得
	NODISCARD bool GetActive() const {
		return active;
	}

	// @brief ゲームオブジェクトを生成する
	NODISCARD static std::shared_ptr<GameObject> Create(std::string_view name, std::optional<bool> active = std::nullopt);

	// @brief Sprite ゲームオブジェクトを生成する
	NODISCARD static std::shared_ptr<GameObject> Create(std::string_view name, std::string_view textureName, int order, std::optional<bool> active = std::nullopt, std::optional<bool> visible = std::nullopt);

	// @brief Sprite Animation ゲームオブジェクトを生成する
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

	/// @brief 公開
	friend struct glz::meta<GameObject>;
};

/// @brief メタ情報を定義
template<>
struct glz::meta<GameObject> {
	static constexpr auto value = object(
		"name"    , &GameObject::name,
		"id"      , &GameObject::instanceID,
		"active"  , &GameObject::active,
		"children", &GameObject::children
	);
};

/// @brief ルート
struct GameObjectRoot {
	std::vector<std::shared_ptr<GameObject>> gameObjects;
};

#endif 
