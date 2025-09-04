#ifndef NUMERIC_CONCEPT_HPP
#define NUMERIC_CONCEPT_HPP

/*
    @file NumericConcept.hpp
    @brief concept ‚ğ’è‹`
    @author Ay
    @date 2025/08/03
*/

#include <concepts>

namespace Concept {
    // @brief ®”Œ^§–ñ
    template <typename T>
    concept is_integral = std::is_integral_v<T>;

    // @brief •‚“®¬”“_Œ^§–ñ
    template <typename T>
    concept is_floating = std::is_floating_point_v<T>;

    // @brief ”’lŒ^§–ñ
    template <typename T>
    concept is_numeric = std::is_integral_v<T> || std::is_floating_point_v<T>;
}

#endif
