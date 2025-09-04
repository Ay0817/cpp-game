#ifndef CPP_VERSION_HPP
#define CPP_VERSION_HPP

/*
    @file CppVersion.hpp
    @brief C++のバージョンに合わせて設定の変更を行う。
    @author Ay
    @date 2025/08/03
*/

// C++ バージョン
constexpr long CPP23 = 202300;
constexpr long CPP20 = 202000;
constexpr long CPP17 = 201700;

// NODISCARDマクロ定義
#if (__cplusplus >= CPP23)
    #define NODISCARD_CPP23(s) [[nodiscard(s)]]
    #define NODISCARD_CPP20 [[nodiscard]]
    #define NODISCARD       [[nodiscard]]
#elif (__cplusplus >= CPP20)
    #define NODISCARD_CPP23 // empty
    #define NODISCARD_CPP20 [[nodiscard]]
    #define NODISCARD       [[nodiscard]]
#elif (__cplusplus >= CPP17)
    #define NODISCARD_CPP23 // empty
    #define NODISCARD_CPP20 // empty
    #define NODISCARD       [[nodiscard]]
#else
    #define NODISCARD_CPP23 // empty
    #define NODISCARD_CPP20 // empty
    #define NODISCARD       // empty
#endif

#endif
