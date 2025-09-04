#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>
#include <string_view>
#include <memory>

#include "CppVersion.hpp"
#include "Hash.hpp"

// @brief Base class for all objects.
class Object {
protected:
	std::string name;
	unsigned int instanceID;
public:
    // @brief コンストラクタ
    Object(std::string_view name) noexcept : name(name) {
        instanceID = internal::hash::create_hash_key(name.data());
    }

    // @brief デストラクタ
    virtual ~Object() = default;

    // @brief == 演算子
    inline bool operator ==(const std::shared_ptr<Object>& other) const {
        return instanceID == other->instanceID;
    }

    // @brief == 演算子
    inline bool operator ==(const Object& other) const {
        return instanceID == other.instanceID;
    }

    // @brief オブジェクト名をセット
    void SetName(std::string_view newName) {
        name = newName;
    }

    // @brief オブジェクト名を取得
    NODISCARD const std::string& GetName() const {
        return name;
    }

    // @brief インスタンス ID を取得
    NODISCARD unsigned int GetInstanceID() const {
        return instanceID;
    }

    // @brief インスタンス ID をセット
    void SetInstanceID(unsigned int newID) {
        instanceID = newID;
    }

    // @brief ハッシュ値を取得
    NODISCARD unsigned int GetHashCode() const {
        return instanceID;
    }

    // @brief 比較
    NODISCARD bool Equals(const std::shared_ptr<Object>& other) const {
        return *this == other;
    }

    // @brief 比較
    NODISCARD static bool Equals(const std::shared_ptr<Object>& lhs, const std::shared_ptr<Object>& rhs) {
        return lhs == rhs;
    }
};

#endif
