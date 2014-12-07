#include <iostream>
#include "Entity.hpp"

void Entity::attachComponent(Component* component) {
    component->init(this);
    mComponents.push_back(std::unique_ptr<Component>(std::move(component)));
}

void Entity::update(int32_t deltaTime) {
    for (auto& component : mComponents) {
        component->update(deltaTime);
    }
}
