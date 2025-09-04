#ifndef VECTOR2_HPP
#define VECTOR2_HPP

/*
    @file Vector2.hpp
    @brief Vector2 ���`
    @author Ay
    @date 2025/08/03
*/

#include <cmath>
#include <algorithm>
#include <format>

#include "IEquatable.hpp"
#include "IStringConvertible.hpp"
#include "CppVersion.hpp"
#include "NumericConcept.hpp"
#include "Math.hpp"

// @brief Vector2
struct NODISCARD Vector2 : public System::IEquatable<Vector2>, public System::IStringConvertible {
    // @brief x ���W
    float x;

    // @brief y ���W
    float y;

    // @brief �f�t�H���g�R���X�g���N�^
    NODISCARD_CPP20 Vector2() = default;

    // @brief �f�t�H���g�R�s�[�R���X�g���N�^
    NODISCARD_CPP20 Vector2(const Vector2&) noexcept = default;

    // @brief �R���X�g���N�^
    NODISCARD_CPP20 constexpr explicit Vector2(float _x, float _y) : x(_x), y(_y) {}

    // @brief �R���X�g���N�^
    template <Concept::is_numeric T>
    NODISCARD_CPP20 constexpr explicit Vector2(T _x, T _y) noexcept : x(static_cast<float>(_x)), y(static_cast<float>(_y)) {}

    // @brief �R�s�[������Z�q
    constexpr Vector2& operator = (const Vector2&) = default;

    // @brief �P�� + ���Z�q
    constexpr Vector2 operator +() const noexcept {
        return *this;
    }

    // @brief �P�� - ���Z�q
    constexpr Vector2 operator -() const noexcept {
        return Vector2(-x, -y);
    }

    // @brief + ���Z�q
    constexpr Vector2 operator +(const Vector2& other) const noexcept {
        return Vector2(x + other.x, y + other.y);
    }

    // @brief - ���Z�q
    constexpr Vector2 operator -(const Vector2& other) const noexcept {
        return Vector2(x - other.x, y - other.y);
    }

    // @brief * ���Z�q
    constexpr Vector2 operator *(const Vector2& other) const noexcept {
        return Vector2(x * other.x, y * other.y);
    }

    // @brief / ���Z�q
    constexpr Vector2 operator /(const Vector2& other) const noexcept {
        return Vector2(x / other.x, y / other.y);
    }

    // @brief * ���Z�q
    constexpr Vector2 operator *(float other) const noexcept {
        return Vector2(x * other, y * other);
    }

    // @brief / ���Z�q
    constexpr Vector2 operator /(float other) const noexcept {
        return Vector2(x / other, y / other);
    }

    // @brief += ���Z�q
    constexpr Vector2& operator +=(const Vector2& other) noexcept {
        x += other.x;
        y += other.y;

        return *this;
    }

    // @brief -= ���Z�q
    constexpr Vector2& operator -=(const Vector2& other) noexcept {
        x -= other.x;
        y -= other.y;

        return *this;
    }

    // @brief *= ���Z�q
    constexpr Vector2& operator *=(const Vector2& other) noexcept {
        x *= other.x;
        y *= other.y;

        return *this;
    }

    // @brief /= ���Z�q
    constexpr Vector2& operator /=(const Vector2& other) noexcept {
        x /= other.x;
        y /= other.y;

        return *this;
    }

    // @brief *= ���Z�q
    constexpr Vector2& operator *=(float other) noexcept {
        x *= other;
        y *= other;

        return *this;
    }

    // @brief /= ���Z�q
    constexpr Vector2& operator /=(float other) noexcept {
        x /= other;
        y /= other;

        return *this;
    }

#if (__cplusplus >= CPP20)
    NODISCARD std::partial_ordering operator <=>(const Vector2& other) const noexcept {
        return Magnitude() <=> other.Magnitude();
    }
#else 
    NODISCARD bool operator <(const Vector2& other) const noexcept {
        return Magnitude() < other.Magnitude();
    }

    NODISCARD bool operator <=(const Vector2& other) const noexcept {
        return Magnitude() <= other.Magnitude();
    }

    NODISCARD bool operator >(const Vector2& other) const noexcept {
        return Magnitude() > other.Magnitude();
    }

    NODISCARD bool operator >=(const Vector2& other) const noexcept {
        return Magnitude() >= other.Magnitude();
    }
#endif
    // @brief != ���Z�q
    constexpr bool operator !=(const Vector2& other) const noexcept {
        return !(*this == other);
    }

    // @brief == ���Z�q
    constexpr bool operator ==(const Vector2& other) const noexcept {
        auto num = x - other.x;
        auto num2 = y - other.y;
        auto num3 = num * num + num2 * num2;

        return num3 < math::EPSILON_SQUARED;
    }

    // @brief ++ ���Z�q
    constexpr Vector2& operator ++() noexcept {
        ++x;
        ++y;

        return *this;
    }

    // @brief ++ ���Z�q
    constexpr Vector2& operator --() noexcept {
        --x;
        --y;

        return *this;
    }

    //@brief �v�f��ݒ肷��
    void Set(float _x, float _y) noexcept {
        x = _x;
        y = _y;
    }

    // @brief ���`��ԁi�N�����v�t���j
    NODISCARD static constexpr Vector2 Lerp(const Vector2& a, const Vector2& b, float t) noexcept {
        t = math::Clamp01(t);

        return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
    }

    // @brief ���`��ԁi�N�����v�Ȃ��j
    NODISCARD static constexpr Vector2 LerpUnclamped(const Vector2& a, const Vector2& b, float t) noexcept {
        return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
    }

    // @brief �x�N�g��������ֈ�苗�������߂Â���
    NODISCARD static constexpr Vector2 MoveTowards(const Vector2& current, const Vector2& target, float maxDistanceDelta) noexcept {
        auto num = target.x - current.x;
        auto num2 = target.y - current.y;
        auto num3 = num * num + num2 * num2;

        if (num3 == 0.f || (maxDistanceDelta >= 0.f && num3 <= maxDistanceDelta * maxDistanceDelta)) {
            return target;
        }

        float num4 = math::Sqrt(num3);

        return Vector2(current.x + num / num4 * maxDistanceDelta, current.y + num2 / num4 * maxDistanceDelta);
    }

    // @brief
    NODISCARD static constexpr Vector2 Scale(const Vector2& a, const Vector2& b) noexcept {
        return Vector2(a.x * b.x, a.y * b.y);
    }

    // @brief ���̃x�N�g�����X�P�[�����O���Z����
    void Scale(const Vector2& scale) noexcept {
        *this *= scale;
    }

    // @brief �w��x�N�g���𐳋K���������ʂ�Ԃ�
    void Normalize() {
        auto num = Magnitude();

        if (num > math::EPSILON) {
            *this /= num;
        }
    }

    // @brief �w��x�N�g���𐳋K���������ʂ�Ԃ�
    NODISCARD static const Vector2 Normalize(const Vector2& value) noexcept {
        auto num = Magnitude(value);

        if (num > math::EPSILON) {
            return value / num;
        }

        return zero();
    }

    // @brief �@���ɑ΂��ăx�N�g���𔽎˂������x�N�g����Ԃ�
    NODISCARD static constexpr Vector2 Reflect(const Vector2& inDirection, const Vector2& inNormal) noexcept {
        float num = -2.f * Dot(inNormal, inDirection);

        return Vector2(num * inNormal.x + inDirection.x, num * inNormal.y + inDirection.y);
    }

    // @brief �^����ꂽ�x�N�g���̐����x�N�g����Ԃ�
    NODISCARD static constexpr Vector2 Perpendicular(const Vector2& inDirection) {
        return Vector2(0.f - inDirection.y, inDirection.x);
    }

    // @return ���ς�Ԃ�
    NODISCARD constexpr float Dot(const Vector2& other) const noexcept {
        return x * other.x + y * other.y;
    }

    // @return ���ς�Ԃ�
    NODISCARD static constexpr float Dot(const Vector2& lhs, const Vector2& rhs) noexcept {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    // @return �O�ς�Ԃ�
    NODISCARD constexpr float Cross(const Vector2& other) const noexcept {
        return x * other.y - y * other.x;
    }

    // @return �O�ς�Ԃ�
    NODISCARD static constexpr float Cross(const Vector2& lhs, const Vector2& rhs) noexcept {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    // @brief 2�x�N�g���Ԃ̊p�x�i�x�j��Ԃ�
    NODISCARD static float Angle(const Vector2& from, const Vector2& to) {
        auto num = math::Sqrt(from.SqrMagnitude() * to.SqrMagnitude());

        if (num < 1e-15f) {
            return 0.f;
        }

        float num2 = math::Clamp(Dot(from, to) / num, -1.f, 1.f);

        return math::Acos(num2) * 57.29578f;
    }

    // @brief 2�̃x�N�g���Ԃ̕����t���p�x���v�Z����
    NODISCARD static float SignedAngle(const Vector2& from, const Vector2& to) {
        float num = Angle(from, to);
        float num2 = math::Sign(from.x * to.y - from.y * to.x);

        return num * num2;
    }

    // @brief 2�_�Ԃ̋�����Ԃ�
    NODISCARD static float Distance(const Vector2& a, const Vector2& b) {
        float num = a.x - b.x;
        float num2 = a.y - b.y;

        return math::Sqrt(num * num + num2 * num2);
    }

    // @brief �v�f���Ƃ̍ŏ��l
    NODISCARD static constexpr Vector2 Min(const Vector2& lhs, const Vector2& rhs) {
        return Vector2(math::Min(lhs.x, rhs.x), math::Min(lhs.y, rhs.y));
    }

    // @brief �v�f���Ƃ̍ő�l
    NODISCARD static constexpr Vector2 Max(const Vector2& lhs, const Vector2& rhs) {
        return Vector2(math::Max(lhs.x, rhs.x), math::Max(lhs.y, rhs.y));
    }

    // @return ������Ԃ�
    NODISCARD float Magnitude() const noexcept {
        return math::Sqrt(x * x + y * y);
    }

    // @brief �w��x�N�g���̑傫����Ԃ�
    NODISCARD static float Magnitude(const Vector2& other) noexcept {
        return math::Sqrt(other.x * other.x + other.y * other.y);
    }

    // @return ������2���Ԃ�
    NODISCARD constexpr float SqrMagnitude() const noexcept {
        return x * x + y * y;
    }

    // @return �I�t�Z�b�g���K�����ꂽ�x�N�g����Ԃ�
    NODISCARD constexpr Vector2 OffSet(float dx, float dy) const noexcept {
        return Vector2(x + dx, y + dy);
    }

    // @return {0.f, 0.f}
    NODISCARD static constexpr Vector2 zero() noexcept {
        return Vector2(0.0f, 0.0f);
    }

    // @return {1.f, 1.f}
    NODISCARD static constexpr Vector2 one() noexcept {
        return Vector2(1.0f, 1.0f);
    }

    // @return {0.f, -1.f}
    NODISCARD static constexpr Vector2 up() noexcept {
        return Vector2(0.0f, -1.0f);
    }

    // @return {0.f, 1.f}
    NODISCARD static constexpr Vector2 down() noexcept {
        return Vector2(0.0f, 1.0f);
    }

    // @return {1.f, 0.f}
    NODISCARD static constexpr Vector2 right() noexcept {
        return Vector2(1.0f, 0.0f);
    }

    // @return {-1.f, 0.f}
    NODISCARD static constexpr Vector2 left() noexcept {
        return Vector2(-1.0f, 0.0f);
    }

    // @brief ���l����
    NODISCARD virtual bool Equals(const Vector2& other) const override {
        return *this == other;
    }

    // @brief ������ϊ�
    NODISCARD std::string ToString() const override {
        return std::format("Vector2({}, {})", x, y);
    }
};

#endif
