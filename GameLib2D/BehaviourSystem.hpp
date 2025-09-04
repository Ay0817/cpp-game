#ifndef BEHAVIOUR_SYSTEM_HPP
#define BEHAVIOUR_SYSTEM_HPP

#include <vector>
#include <memory>

#include "Config.hpp"

/*�O���錾*/
class Behaviour;

/// @brief 
class BehaviourSystem final {
	CLASS_SINGLETON_BODY(BehaviourSystem)
private:
	std::vector<std::shared_ptr<Behaviour>> behaviours;
public:
	/// @brief Behaviour ��ǉ�����B
	/// @param behaviour �Q�Ɛ�
	void Register(const std::shared_ptr<Behaviour>& behaviour);

	/// @brief �C���X�^���X������ɌĂ΂�鏈��
	void Awake();

	/// @brief Update �O��1�x�����Ă΂�鏈��
	void Begin();

	/// @brief �X�V����
	void Update(float deltaTime);

	/// @brief �X�V����
	void FixedUpdate(float deltaTime);

	/// @brief �X�V����
	void LateUpdate(float deltaTime);

	/// @brief �I������
	void End();

	/// @brief �I�u�W�F�N�g���L���ɂȂ������ɌĂяo�����
	void OnEnable();

	/// @brief �I�u�W�F�N�g�������ɂȂ������ɌĂяo�����
	void OnDisable();
};

#define BehaviourSys BehaviourSystem::GetInstance()

#endif 
