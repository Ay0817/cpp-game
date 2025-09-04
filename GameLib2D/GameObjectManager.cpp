#include "GameObjectManager.hpp"
#include "GameObject.hpp"
#include "Behaviour.hpp"
#include "BehaviourSystem.hpp"
#include "Transform.hpp"

void GameObjectManager::RequestDestroy(const std::string& name) {
    toDestroy.emplace_back(internal::hash::create_hash_key(name));
}

void GameObjectManager::RemoveRecursively(const std::shared_ptr<GameObject>& object) {
    if (!object) return;

    // 子を先に削除
    for (auto& childTransform : object->transform->GetChildren()) {
        if (auto childObj = childTransform->gameObject.lock()) {
            RemoveRecursively(childObj);
        }
    }

    // 自分を削除
    auto destroyObjName = object->GetName();
    auto key = internal::hash::create_hash_key(destroyObjName);

    objectMap.erase(key);

    Logger::Log("ゲームオブジェクト[" + destroyObjName + "]を破棄しました。");
}

void GameObjectManager::ProcessDestroy() {
    for (const auto& id : toDestroy) {
        if (auto it = objectMap.find(id); it != objectMap.end()) {
            const auto& object = it->second;
            const auto destroyObjName = object->GetName();

            for (auto& childTransform : object->transform->GetChildren()) {
                if (auto childObj = childTransform->gameObject.lock()) {
                    RemoveRecursively(childObj);
                }
            }

            if (auto parentTrs = object->transform->GetParent().lock()) {
                if (auto parentObj = parentTrs->gameObject.lock()) {
                    parentObj->RemoveChild(object);
                    parentObj->transform->RemoveChild(object->transform);
                }
            }
            objectMap.erase(it);

            Logger::Log("ゲームオブジェクト[" + destroyObjName + "]を破棄しました。");
        }
    }

    toDestroy.clear();
}

void GameObjectManager::NewSceneInit() {
    objectMap.clear();
    toDestroy.clear();
}

void GameObjectManager::UpdateEnableState() {

}

void GameObjectManager::Register(const std::shared_ptr<GameObject>& object) {
    std::string originalName = object->GetName();
    std::string newName = originalName;
    size_t counter = 1;

    while (objectMap.contains(internal::hash::create_hash_key(newName))) {
        newName = originalName + std::to_string(counter++);
    }

    object->SetName(newName);
    auto newId = internal::hash::create_hash_key(newName);
    object->SetInstanceID(newId);

    objectMap[newId] = object;

    Logger::Log("ゲームオブジェクト名[" + object->GetName() + "]が登録されました。");
}

void GameObjectManager::DontDestroy(const std::shared_ptr<GameObject>& object) {
    dontDestroyObjectMap[object->GetInstanceID()] = object;
}

void GameObjectManager::Destroy(const std::shared_ptr<Object>& obj) {
    RequestDestroy(obj->GetName());
}

void GameObjectManager::Destroy(const std::string& name) {
    RequestDestroy(name);
}

const std::shared_ptr<GameObject> GameObjectManager::Find(const std::string& name) const {
    auto it = objectMap.find(internal::hash::create_hash_key(name));

    if (it != objectMap.end()) {
        return it->second;
    }

    Logger::LogError("GameObjectが見つかりませんでした。");

    return nullptr;
}

std::shared_ptr<GameObject> GameObjectManager::FindWithTag(const std::string& tag) const {
    for (const auto& [id, obj] : objectMap) {
        if (obj->CompareTag(tag)) {
            return obj;
        }
    }

    Logger::LogError("GameObjectが見つかりませんでした。");

    return nullptr;
}

const std::vector<std::shared_ptr<GameObject>> GameObjectManager::FindGameObjectsWithTag(const std::string& tag) const {
    std::vector<std::shared_ptr<GameObject>> result;
    for (const auto& [id, obj] : objectMap) {
        if (obj->CompareTag(tag.data())) {
            result.emplace_back(obj);
        }
    }
    return result;
}

NODISCARD const std::vector<std::shared_ptr<GameObject>> GameObjectManager::RegistedAllObjects() const {
    std::vector<std::shared_ptr<GameObject>> result;

    for (const auto& [id, obj] : objectMap) {
        result.emplace_back(obj);
    }

    return result;
}

