#include "Behaviour.hpp"

Behaviour::Behaviour(std::weak_ptr<GameObject> owner)
	: Component(owner) {
}

Behaviour::~Behaviour() {
	End();
}

void Behaviour::Invoke(std::function<void()> func, float sec) {
	//TODO: 設定した時間後に関数を呼び出す処理
}

void Behaviour::InvokeRepeating(std::function<void()> func, float sec, float repeatRate) {
	//TODO: 設定した時間後に関数を呼び出すリピート処理
}
