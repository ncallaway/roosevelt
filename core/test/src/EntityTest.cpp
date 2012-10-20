#include "Entity.h"
#include "BaseComponent.h"
#include "gtest/gtest.h"

class TestComponent : public BaseComponent {
    public:
        TestComponent();
        static const ComponentType TYPE;
};

TestComponent::TestComponent() : BaseComponent(TYPE) {
}

const ComponentType TestComponent::TYPE = EntityComponent::RegisterComponent();

TEST(EntityId, SetId) {
	Entity* entity = new Entity();

	entity->SetId("test");
	EXPECT_EQ("test", entity->GetId());
}

TEST(EntityComponent, HasComponent) {
	Entity* entity = new Entity();

    /* Start with no components */
    EXPECT_FALSE(entity->HasComponent(TestComponent::TYPE));

    /* Have a component after adding one. */
    entity->AddComponent(new TestComponent());
    EXPECT_TRUE(entity->HasComponent(TestComponent::TYPE));

    /* Don't have a component after adding one. */
    entity->RemoveComponent(TestComponent::TYPE);
    EXPECT_FALSE(entity->HasComponent(TestComponent::TYPE));
}

TEST(EntityComponent, GetComponent) {
	Entity* entity = new Entity();
     EntityComponent* testComponent = new TestComponent();

    /* Null when there is no component */
    EXPECT_EQ(NULL, entity->GetComponent(TestComponent::TYPE));

    /* Now return the type we've added */
    entity->AddComponent(testComponent);
    EXPECT_EQ(testComponent, entity->GetComponent(TestComponent::TYPE));

    /* And null after we remove it */
    entity->RemoveComponent(TestComponent::TYPE);
    EXPECT_EQ(NULL, entity->GetComponent(TestComponent::TYPE));
}

TEST(EntityComponent, AddComponent) {
	Entity* entity = new Entity();
    EntityComponent* testComponent = new TestComponent();

    /* Can add the component */
    EXPECT_TRUE(entity->AddComponent(testComponent));

    /* Can get the component we originally added */
    EXPECT_EQ(testComponent, entity->GetComponent(TestComponent::TYPE));

    /* Can re-add the same component */
    EXPECT_TRUE(entity->AddComponent(testComponent));

    /* Cannot add a different component of the same type */
    EntityComponent* alternateTestComponent = new TestComponent();
    EXPECT_FALSE(entity->AddComponent(alternateTestComponent));

    /* After trying to add a different component, we still get the original back */
    EXPECT_EQ(testComponent, entity->GetComponent(TestComponent::TYPE));

    /* Cannot add a NULL component */
    EXPECT_FALSE(entity->AddComponent(NULL));

    /* After removing can re-add the alternate component */
    entity->RemoveComponent(TestComponent::TYPE);
    EXPECT_TRUE(entity->AddComponent(alternateTestComponent));
    EXPECT_EQ(alternateTestComponent, entity->GetComponent(TestComponent::TYPE));
}

TEST(EntityComponent, RemoveComponent) {
	Entity* entity = new Entity();

    /* Nothing happens when there is nothing to remove. */
    EXPECT_FALSE(entity->RemoveComponent(TestComponent::TYPE));

    /* Can now remove the component */
    entity->AddComponent(new TestComponent());
    EXPECT_TRUE(entity->RemoveComponent(TestComponent::TYPE));

    /* And now there's nothing to remove */
    EXPECT_FALSE(entity->RemoveComponent(TestComponent::TYPE));
}

