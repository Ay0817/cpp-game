#ifndef COLOR_HPP
#define COLOR_HPP

#include <format>

#include "CppVersion.hpp"
#include "Math.hpp"
#include "IStringConvertible.hpp"

// @brief Color
struct Color : public System::IStringConvertible {
    // @brief red
    unsigned int r;

    // @brief green
    unsigned int g;

    // @brief blue
    unsigned int b;

    // @brief alpha
    unsigned int a;

    // @brief �ŏ��l
    static constexpr unsigned int MIN = 0;

    // @brief �ő�l
    static constexpr unsigned int MAX = 255;

    // @brief �R���X�g���N�^
    NODISCARD_CPP20 Color() noexcept = default;

    // @brief �R���X�g���N�^
    NODISCARD_CPP20 Color(const Color&) noexcept = default;

    // @brief �R���X�g���N�^
    NODISCARD_CPP20 constexpr explicit Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a) noexcept :
        r(math::Clamp(r, MIN, MAX)), g(math::Clamp(g, MIN, MAX)), b(math::Clamp(b, MIN, MAX)), a(math::Clamp(a, MIN, MAX)) {
    }

    // @brief �f�X�g���N�^
    constexpr ~Color() noexcept = default;

    // @brief �R�s�[������Z�q
    constexpr Color& operator = (const Color&) = default;

    // @brief �v�f��ݒ�
    void Set(unsigned int _r, unsigned int _g, unsigned int _b, unsigned int _a) noexcept {
        r = math::Clamp(r, MIN, MAX);
        g = math::Clamp(g, MIN, MAX);
        b = math::Clamp(b, MIN, MAX);
        a = math::Clamp(a, MIN, MAX);
    }

    // @brief 16�i�ɂ��ĕԂ�
    NODISCARD constexpr unsigned int ToUInt() const noexcept {
        return (r << 16) | (g << 8) | b;
    }

    // @brief ������ϊ�
    NODISCARD std::string ToString() const override {
        return std::format("Color({}, {}, {}, {})", r, g, b, a);
    }

    // @return color red
    NODISCARD static constexpr Color red() noexcept {
        return Color(255, 0, 0, 255);
    }

    // @return color green
    NODISCARD static constexpr Color green() noexcept {
        return Color(0, 255, 0, 255);
    }

    // @return color blue
    NODISCARD static constexpr Color blue() noexcept {
        return Color(0, 0, 255, 255);
    }

    // @return color yellow
    NODISCARD static constexpr Color yellow() noexcept {
        return Color(255, 255, 0, 255);
    }

    // @return color magenta
    NODISCARD static constexpr Color magenta() noexcept {
        return Color(255, 0, 255, 255);
    }

    // @return color cyan
    NODISCARD static constexpr Color cyan() noexcept {
        return Color(0, 255, 255, 255);
    }

    // @return color orange
    NODISCARD static constexpr Color orange() noexcept {
        return Color(255, 165, 0, 255);
    }

    // @return color purple
    NODISCARD static constexpr Color purple() noexcept {
        return Color(128, 0, 128, 255);
    }

    // @return color gray
    NODISCARD static constexpr Color gray() noexcept {
        return Color(125, 125, 125, 255);
    }

    // @return color black
    NODISCARD static constexpr Color black() noexcept {
        return Color(0, 0, 0, 255);
    }

    // @return color white
    NODISCARD static constexpr Color white() noexcept {
        return Color(255, 255, 255, 255);
    }
};

#endif 
