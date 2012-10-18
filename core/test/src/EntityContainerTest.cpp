#include "EntityContainer.h"
#include "Entity.h"
#include "gtest/gtest.h"

TEST(EntityContainer, AddEntity) {
    EntityContainer* container = new EntityContainer();
    Entity* entity = new Entity();
    Entity* secondEntity = new Entity();
    
    /* Can add new entities */
    EXPECT_TRUE(container->AddEntity(entity));
    
    /* Cannot add duplicate entities */
    EXPECT_FALSE(container->AddEntity(entity));

    /* Can add different entities */
    EXPECT_TRUE(container->AddEntity(secondEntity));

    /* Can re-add removed entities */
    container->RemoveEntity(entity);
    EXPECT_TRUE(container->AddEntity(entity));

    /* Cannot add NULL entities */
    EXPECT_FALSE(container->AddEntity(NULL));
}

TEST(EntityContainer, RemoveEntity) {
    EntityContainer* container = new EntityContainer();
    Entity* entity = new Entity();
    
    /* Can not remove non-existant entities */
    EXPECT_FALSE(container->RemoveEntity(entity));
    
    /* Can remove added entities */
    container->AddEntity(entity);
    EXPECT_TRUE(container->RemoveEntity(entity));

    /* Can not remove the entity again */
    EXPECT_FALSE(container->RemoveEntity(entity));

    /* Can not remove a NULL entity */
    EXPECT_FALSE(container->RemoveEntity(NULL));
}

TEST(EntityContainer, HasEntity) {
    EntityContainer* container = new EntityContainer();
    Entity* entity = new Entity();
    Entity* secondEntity = new Entity();
    
    /* Nothing before additions */
    EXPECT_FALSE(container->HasEntity(entity));
    
    /* Has newly added entities */
    container->AddEntity(entity);
    EXPECT_TRUE(container->HasEntity(entity));

    /* Does not have other entities */
    EXPECT_FALSE(container->HasEntity(secondEntity));

    /* Does not have removed entities */
    container->RemoveEntity(entity);
    EXPECT_FALSE(container->HasEntity(entity));

    /* Does not have a NULL entity */
    EXPECT_FALSE(container->RemoveEntity(NULL));
}

TEST(EntityContainer, Query) {
    EntityContainer* container = new EntityContainer();
    Entity* entity = new Entity();
    Entity* secondEntity = new Entity();
     std::set<Entity*> elements = container->Query();
    
    /* Newly constructed containers have no elements */
    EXPECT_EQ(0, elements.size());
    
    /* Have entity (and only entity) */
    container->AddEntity(entity);
    elements = container->Query();
    EXPECT_EQ(1, elements.size());
    EXPECT_EQ(1, elements.count(entity));

    /* Modifications DO NOT effect the underlying container */
    elements.clear();
    elements = container->Query();
    EXPECT_EQ(1, elements.size());
    EXPECT_EQ(1, elements.count(entity));

    /* Other entities are tracked properly */
    container->AddEntity(secondEntity);
    elements = container->Query();
    EXPECT_EQ(2, elements.size());
    EXPECT_EQ(1, elements.count(entity));
    EXPECT_EQ(1, elements.count(secondEntity));

    /* Query responds to removals */
    container->RemoveEntity(entity);
    elements = container->Query();
    EXPECT_EQ(1, elements.size());
    EXPECT_EQ(1, elements.count(secondEntity));
}
