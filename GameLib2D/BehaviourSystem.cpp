#include "BehaviourSystem.hpp"
#include "Behaviour.hpp"

void BehaviourSystem::Register(const std::shared_ptr<Behaviour>& behaviour) {
	behaviours.emplace_back(behaviour);

	Logger::Log("BehaviourSystem ‚É[" + behaviour->GetName() + "]‚ª“o˜^‚³‚ê‚Ü‚µ‚½B");
}

void BehaviourSystem::Awake() {
	for (const auto& behaviour : behaviours) {
		if (behaviour->GetEnable() && !behaviour->GetAwakeState()) {
			behaviour->Awake();
			behaviour->SetAwakeState(true);
		}
	}
}

void BehaviourSystem::Begin() {
	for (const auto& behaviour : behaviours) {
		if (behaviour->GetEnable() && !behaviour->GetBeginState()) {
			behaviour->Begin();
			behaviour->SetBeginState(true);
		}
	}
}

void BehaviourSystem::Update(float deltaTime) {
	for (const auto& behaviour : behaviours) {
		if (behaviour->GetEnable()) {
			behaviour->Update(deltaTime);
		}
	}
}

void BehaviourSystem::FixedUpdate(float deltaTime) {
	for (const auto& behaviour : behaviours) {
		if (behaviour->GetEnable()) {
			behaviour->FixedUpdate(deltaTime);
		}
	}
}

void BehaviourSystem::LateUpdate(float deltaTime) {
	for (const auto& behaviour : behaviours) {
		if (behaviour->GetEnable()) {
			behaviour->LateUpdate(deltaTime);
		}
	}
}

void BehaviourSystem::End() {
	for (const auto& behaviour : behaviours) {
		if (behaviour->GetEnable()) {
			behaviour->End();
		}
	}
}

void BehaviourSystem::OnEnable() {
	for (const auto& behaviour : behaviours) {
		if (behaviour->GetEnable()) {
			behaviour->OnEnable();
		}
	}
}

void BehaviourSystem::OnDisable() {
	for (const auto& behaviour : behaviours) {
		if (behaviour->GetEnable()) {
			behaviour->OnDisable();
		}
	}
}
