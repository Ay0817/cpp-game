#ifndef GAME_OBJECT_MANAGER_HPP
#define GAME_OBJECT_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include <string>

#include "Config.hpp"

/*--�O���錾--*/
class GameObject;
class Object;

// @brief 
class GameObjectManager final {
	CLASS_SINGLETON_BODY(GameObjectManager)
private:
	std::unordered_map<unsigned int, std::shared_ptr<GameObject>> objectMap;
	std::vector<unsigned int> toDestroy;
	std::unordered_map<unsigned int, std::shared_ptr<GameObject>> dontDestroyObjectMap;

	// @brief �j���v��
	void RequestDestroy(const std::string& name);

	// @brief �ċA�I�ɔj�����s��
	void RemoveRecursively(const std::shared_ptr<GameObject>& object);
public:
	// @brief �V�[���J�ڌ�ɌĂяo������
	void NewSceneInit();

	// @brief Behaviour �̏�Ԃ��Ď��ƍX�V���s��
	void UpdateEnableState();

	// @brief �o�^����
	void Register(const std::shared_ptr<GameObject>& object);

	// @brief �t���[���̏I���Ŕj��
	void ProcessDestroy();

	// @brief �V�[���J�ڎ��ɔj�����Ȃ��I�u�W�F�N�g��o�^
	void DontDestroy(const std::shared_ptr<GameObject>& object);

	// @brief �I�u�W�F�N�g��j��
	void Destroy(const std::shared_ptr<Object>& obj);

	// @brief �Q�[���I�u�W�F�N�g��j��
	void Destroy(const std::string& name);

	// @brief �Q�[���I�u�W�F�N�g��T��
	NODISCARD const std::shared_ptr<GameObject> Find(const std::string& name) const;

	// @brief �w�肵���^�O�����Q�[���I�u�W�F�N�g��T��
	NODISCARD std::shared_ptr<GameObject> FindWithTag(const std::string& tag) const;

	// @brief �w�肵���^�O�����Q�[���I�u�W�F�N�g��T��
	NODISCARD const std::vector<std::shared_ptr<GameObject>> FindGameObjectsWithTag(const std::string& tag) const;

	// @brief�@�o�^�ς݂̃Q�[���I�u�W�F�N�g�����ׂĕԂ�
	NODISCARD const std::vector<std::shared_ptr<GameObject>> RegistedAllObjects() const;
};

#endif
