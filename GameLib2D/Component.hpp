#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <vector>

#include "Object.hpp"
#include "CppVersion.hpp"
#include "ComponentConcept.hpp"

/*--前方宣言--*/
class GameObject;

// @brief コンポーネントの基底クラス。
class Component : public Object {
protected:
	std::string tag;
public:
	std::weak_ptr<GameObject> gameObject;
public:
	// @brief コンストラクタ
	NODISCARD_CPP20 Component() = default;

	// @brief コンストラクタ
	NODISCARD_CPP20 Component(std::weak_ptr<GameObject> owner);

	// @brief デストラクタ
	virtual ~Component() noexcept = default;

	// @brief タグをセットする
	void SetTag(const std::string& newTag) {
		tag = newTag;
	}

	// @brief タグを返す
	NODISCARD const std::string& GetTag() const {
		return tag;
	}

	// @brief 与えられているタグと一致しているか？
	NODISCARD bool CompareTag(const std::string& other) const {
		return tag == other;
	}

	// @brief コンポーネントを追加
	template <Concept::is_component T>
	std::shared_ptr<T> AddComponent();

	// @brief コンポーネントを取得
	template <Concept::is_component T>
	NODISCARD std::shared_ptr<T> GetComponent() const;

	// @brief コンポーネントを取得
	template <Concept::is_component T>
	NODISCARD const std::vector<std::shared_ptr<T>> GetComponents() const;
};

#include "Component.inl"

#endif
