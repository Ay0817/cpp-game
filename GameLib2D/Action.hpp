#ifndef ACTION_HPP
#define ACTION_HPP

#include <functional>
#include <vector>

/// @brief �C�ӂ̈������󂯎��֐���o�^�E�폜���A�܂Ƃ߂Ď��s�ł���C�x���g�Ǘ��N���X�B
/// @tparam ...Args 
template <typename... Args>
class Action final {
	using func = std::function<void(Args...)>;
private:
	std::vector<func> listeners;
public:
	/// @brief += ���Z�q
	/// @param call �ǉ�����֐�
	/// @return ���g�̎Q��
	constexpr Action& operator+=(const func& call) {
		listeners.emplace_back(call);

		return *this;
	}

	/// @brief -= ���Z�q
	/// @param call ���O����֐�
	/// @return ���g�̎Q��
	constexpr Action& operator-=(const func& call) {
		std::erase_if(listeners, [&](const auto& f) {
			return f.target_type() == call.target_type();
			});

		return *this;
	}

	/// @brief �֐���ǉ�
	/// @param call �ǉ�����֐�
	void Add(const func& call) {
		*this += call;
	}

	/// @brief �֐������O
	/// @param call ���O����֐�
	void Remove(const func& call) {
		*this -= call;
	}

	/// @brief �ێ����Ă���֐������s
	/// @param ...args �֐��̈���
	void Invoke(Args... args) {
		for (auto& listener : listeners) {
			listener(args...);
		}
	}
};

#endif
