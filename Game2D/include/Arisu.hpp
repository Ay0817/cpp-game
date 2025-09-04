#ifndef ARISU_HPP
#define ARISU_HPP

#include <GameLib2D.hpp>
#include <Audio.hpp>

class Arisu : public Behaviour {
private:
	float speed = 0.f;

	std::weak_ptr<Audio> audio;
public:
	// @brief コンストラクタ
	NODISCARD_CPP20 Arisu(std::weak_ptr<GameObject> owner);

	// @brief デストラクタ
	virtual ~Arisu() = default;

	// @brief インスタンス生成後に呼ばれる処理
	virtual void Begin() override;

	// @brief 更新処理
	virtual void Update(float deltaTime) override;
};

#endif
