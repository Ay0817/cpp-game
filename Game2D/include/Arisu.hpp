#ifndef ARISU_HPP
#define ARISU_HPP

#include <GameLib2D.hpp>
#include <Audio.hpp>

class Arisu : public Behaviour {
private:
	float speed = 0.f;

	std::weak_ptr<Audio> audio;
public:
	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Arisu(std::weak_ptr<GameObject> owner);

	// @brief �f�X�g���N�^
	virtual ~Arisu() = default;

	// @brief �C���X�^���X������ɌĂ΂�鏈��
	virtual void Begin() override;

	// @brief �X�V����
	virtual void Update(float deltaTime) override;
};

#endif
