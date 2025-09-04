#include <Asset.hpp>
#include <SpriteRenderer.hpp>

#include "../include/Arisu.hpp"


Arisu::Arisu(std::weak_ptr<GameObject> owner)
	: Behaviour(owner) {
}

void Arisu::Begin() {
	audio = AddComponent<Audio>();
	auto sound = Asset::AssetResolver::GetAsset<Asset::Sound>("Arisu");
	
	if (auto i = audio.lock()) {
		i->SetSound(sound);
		i->SetSoundType(SoundType::Back);
		i->SetVolume(50);
	}

	if (auto obj = gameObject.lock()) {
		obj->transform->SetPosition(Vector2(640.f, 360.f));
		obj->transform->SetScale(0.25f);
	}

	speed = 300.f;
}

void Arisu::Update(float deltaTime) {
	auto src = audio.lock();
	if (!src) return;

	if (Input.GetKeyDown(Keys::ENTER) && !src->IsPlaying()) {
		src->Play();
	}
	if (Input.GetKeyDown(Keys::SPACE) && src->IsPlaying()) {
		src->Stop();
	}

	if (Input.GetKeyDown(Keys::L)) {
		Cursor.SetCursorLock(true);
	}
	if (Input.GetKeyDown(Keys::U)) {
		Cursor.SetCursorLock(false);
	}

	auto obj = gameObject.lock();

	if (!obj) return;

	auto pos = obj->transform->GetPosition();
	auto move = Vector2::zero();

	if (Input.GetKey(Keys::W)) {
		move += Vector2::up();
	}
	if (Input.GetKey(Keys::A)) {
		move += Vector2::left();
	}
	if (Input.GetKey(Keys::S)) {
		move += Vector2::down();
	}
	if (Input.GetKey(Keys::D)) {
		move += Vector2::right();
	}

	if (move != Vector2::zero()) {
		move.Normalize();
		pos += move * speed * deltaTime;
	}

	obj->transform->SetPosition(pos);
}
