#include <gtest/gtest.h>
#include <stdint-gcc.h>

#include "../Entity.hpp"

class TestComponent : public Component {
public:
    TestComponent() = default;
    virtual ~TestComponent() = default;

    bool updateCalled = false;

    virtual void update(int32_t deltaTime) override {
        updateCalled = true;
    };
};

class EntityTests : public ::testing::Test {
protected:
    Entity entity;
};

TEST_F(EntityTests, attachComponent) {
    ASSERT_NO_THROW(entity.attachComponent(new TestComponent()));
}

TEST_F(EntityTests, getComponent) {
    ASSERT_NO_THROW(entity.attachComponent(new TestComponent()));
    ASSERT_NO_THROW(entity.getComponent<TestComponent>());
}

TEST_F(EntityTests, updateComponent) {
    ASSERT_NO_THROW(entity.attachComponent(new TestComponent()));
    ASSERT_FALSE(entity.getComponent<TestComponent>()->updateCalled);
    entity.update(0);
    ASSERT_TRUE(entity.getComponent<TestComponent>()->updateCalled);
}
