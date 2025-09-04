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
    // @brief �R���X�g���N�^
    Object(std::string_view name) noexcept : name(name) {
        instanceID = internal::hash::create_hash_key(name.data());
    }

    // @brief �f�X�g���N�^
    virtual ~Object() = default;

    // @brief == ���Z�q
    inline bool operator ==(const std::shared_ptr<Object>& other) const {
        return instanceID == other->instanceID;
    }

    // @brief == ���Z�q
    inline bool operator ==(const Object& other) const {
        return instanceID == other.instanceID;
    }

    // @brief �I�u�W�F�N�g�����Z�b�g
    void SetName(std::string_view newName) {
        name = newName;
    }

    // @brief �I�u�W�F�N�g�����擾
    NODISCARD const std::string& GetName() const {
        return name;
    }

    // @brief �C���X�^���X ID ���擾
    NODISCARD unsigned int GetInstanceID() const {
        return instanceID;
    }

    // @brief �C���X�^���X ID ���Z�b�g
    void SetInstanceID(unsigned int newID) {
        instanceID = newID;
    }

    // @brief �n�b�V���l���擾
    NODISCARD unsigned int GetHashCode() const {
        return instanceID;
    }

    // @brief ��r
    NODISCARD bool Equals(const std::shared_ptr<Object>& other) const {
        return *this == other;
    }

    // @brief ��r
    NODISCARD static bool Equals(const std::shared_ptr<Object>& lhs, const std::shared_ptr<Object>& rhs) {
        return lhs == rhs;
    }
};

#endif
