#include "Behaviour.hpp"

Behaviour::Behaviour(std::weak_ptr<GameObject> owner)
	: Component(owner) {
}

Behaviour::~Behaviour() {
	End();
}

void Behaviour::Invoke(std::function<void()> func, float sec) {
	//TODO: �ݒ肵�����Ԍ�Ɋ֐����Ăяo������
}

void Behaviour::InvokeRepeating(std::function<void()> func, float sec, float repeatRate) {
	//TODO: �ݒ肵�����Ԍ�Ɋ֐����Ăяo�����s�[�g����
}
