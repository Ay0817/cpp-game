#ifndef BEHAVIOUR_HPP
#define BEHAVIOUR_HPP

#include <functional>

#include "Component.hpp"
#include "GameObjectManager.hpp"

class Behaviour : public Component {
private:
	bool awake = false;
	bool begin = false;
protected:
	bool enable = true;
	bool prevEnable = false;
public:
	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Behaviour() = default;

	// @brief �R���X�g���N�^
	NODISCARD_CPP20 Behaviour(std::weak_ptr<GameObject> owner);

	// @brief �f�X�g���N�^
	virtual ~Behaviour();

	// @brief �C���X�^���X������ɌĂ΂�鏈��
	virtual void Awake() {}

	// @brief Update �O��1�x�����Ă΂�鏈��
	virtual void Begin() {}

	// @brief �X�V����
	virtual void Update(float deltaTime) {}

	// @brief �X�V����
	virtual void FixedUpdate(float deltaTime) {}

	// @brief �X�V����
	virtual void LateUpdate(float deltaTime) {}

	// @brief �I������
	virtual void End() {}

	// @brief �I�u�W�F�N�g���L���ɂȂ������ɌĂяo�����
	virtual void OnEnable() {}

	// @brief �I�u�W�F�N�g�������ɂȂ������ɌĂяo�����
	virtual void OnDisable() {}

	// @brief �ݒ肵�����ԁi�P�ʂ͕b�j��Ɋ֐����Ăяo���܂�
	void Invoke(std::function<void()> func, float sec);

	// @brief �ݒ肵�����ԁi�P�ʂ͕b�j��Ɋ֐����Ăяo���A repeatRate �b���ƂɃ��s�[�g���܂�
	void InvokeRepeating(std::function<void()> func, float sec, float repeatRate);

	// @brief Behaviour �̏�Ԃ��Z�b�g����
	void SetEnable(bool state) {
		enable = state;
	}

	// @brief Behaviour �̏�Ԃ��擾����
	NODISCARD bool GetEnable() const {
		return enable;
	}

	// @brief Awake �����łɌĂяo���ꂽ��?
	NODISCARD bool GetAwakeState() const {
		return awake;
	}

	// @brief Awake �̌Ăяo����Ԃ��Z�b�g
	void SetAwakeState(bool state) {
		awake = state;
	}

	// @brief Begin �����łɌĂяo���ꂽ��?
	NODISCARD bool GetBeginState() const {
		return begin;
	}

	// @brief Begin �̌Ăяo����Ԃ��Z�b�g
	void SetBeginState(bool state) {
		begin = state;
	}

	// @brief Behaviour �̏�Ԃ��Ď��ƍX�V���s��
	void UpdateEnableState();
};

#endif
