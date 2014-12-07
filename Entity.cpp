#include "Entity.hpp"

void Entity::attachComponent(Component component){
    component.init(this);
    mComponents.push_back(component);
}

const Component& Entity::getComponent(const Component::Type& type) {
    for(auto& component : mComponents) {
        if (component.isType(type)) {
            return component;
        }
    }
    throw no_such_component();
}

void Entity::update(int32_t deltaTime) {
    for (auto& component : mComponents) {
        component.update(deltaTime);
    }
}
