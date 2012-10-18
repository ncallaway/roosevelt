#include "Entity.h"
#include "PositionComponent.h"
#include "gtest/gtest.h"

TEST(EntityId, SetId) {
	Entity* entity = new Entity();

	entity->SetId("test");
	EXPECT_EQ("test", entity->GetId());
}

TEST(EntityComponent, HasComponent) {
	Entity* entity = new Entity();

    /* Start with no components */
    EXPECT_FALSE(entity->HasComponent(POSITION_COMPONENT));

    /* Have a component after adding one. */
    entity->AddComponent(new PositionComponent());
    EXPECT_TRUE(entity->HasComponent(POSITION_COMPONENT));

    /* Don't have a component after adding one. */
    entity->RemoveComponent(POSITION_COMPONENT);
    EXPECT_FALSE(entity->HasComponent(POSITION_COMPONENT));
}

TEST(EntityComponent, GetComponent) {
	Entity* entity = new Entity();
     IComponent* positionComponent = new PositionComponent();

    /* Null when there is no component */
    EXPECT_EQ(NULL, entity->GetComponent(POSITION_COMPONENT));

    /* Now return the type we've added */
    entity->AddComponent(positionComponent);
    EXPECT_EQ(positionComponent, entity->GetComponent(POSITION_COMPONENT));

    /* And null after we remove it */
    entity->RemoveComponent(POSITION_COMPONENT);
    EXPECT_EQ(NULL, entity->GetComponent(POSITION_COMPONENT));
}

TEST(EntityComponent, AddComponent) {
	Entity* entity = new Entity();
    IComponent* positionComponent = new PositionComponent();

    /* Can add the component */
    EXPECT_TRUE(entity->AddComponent(positionComponent));

    /* Can get the component we originally added */
    EXPECT_EQ(positionComponent, entity->GetComponent(POSITION_COMPONENT));

    /* Can re-add the same component */
    EXPECT_TRUE(entity->AddComponent(positionComponent));

    /* Cannot add a different component of the same type */
    IComponent* alternatePositionComponent = new PositionComponent();
    EXPECT_FALSE(entity->AddComponent(alternatePositionComponent));

    /* After trying to add a different component, we still get the original back */
    EXPECT_EQ(positionComponent, entity->GetComponent(POSITION_COMPONENT));

    /* Cannot add a NULL component */
    EXPECT_FALSE(entity->AddComponent(NULL));

    /* After removing can re-add the alternate component */
    entity->RemoveComponent(POSITION_COMPONENT);
    EXPECT_TRUE(entity->AddComponent(alternatePositionComponent));
    EXPECT_EQ(alternatePositionComponent, entity->GetComponent(POSITION_COMPONENT));
}

TEST(EntityComponent, RemoveComponent) {
	Entity* entity = new Entity();

    /* Nothing happens when there is nothing to remove. */
    EXPECT_FALSE(entity->RemoveComponent(POSITION_COMPONENT));

    /* Can now remove the component */
    entity->AddComponent(new PositionComponent());
    EXPECT_TRUE(entity->RemoveComponent(POSITION_COMPONENT));

    /* And now there's nothing to remove */
    EXPECT_FALSE(entity->RemoveComponent(POSITION_COMPONENT));
}

