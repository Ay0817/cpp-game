#ifndef ACTION_HPP
#define ACTION_HPP

#include <functional>
#include <vector>

/// @brief 任意の引数を受け取る関数を登録・削除し、まとめて実行できるイベント管理クラス。
/// @tparam ...Args 
template <typename... Args>
class Action final {
	using func = std::function<void(Args...)>;
private:
	std::vector<func> listeners;
public:
	/// @brief += 演算子
	/// @param call 追加する関数
	/// @return 自身の参照
	constexpr Action& operator+=(const func& call) {
		listeners.emplace_back(call);

		return *this;
	}

	/// @brief -= 演算子
	/// @param call 除外する関数
	/// @return 自身の参照
	constexpr Action& operator-=(const func& call) {
		std::erase_if(listeners, [&](const auto& f) {
			return f.target_type() == call.target_type();
			});

		return *this;
	}

	/// @brief 関数を追加
	/// @param call 追加する関数
	void Add(const func& call) {
		*this += call;
	}

	/// @brief 関数を除外
	/// @param call 除外する関数
	void Remove(const func& call) {
		*this -= call;
	}

	/// @brief 保持している関数を実行
	/// @param ...args 関数の引数
	void Invoke(Args... args) {
		for (auto& listener : listeners) {
			listener(args...);
		}
	}
};

#endif
