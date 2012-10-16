#include "Entity.h"
#include "gtest/gtest.h"

TEST(EntityTest, TestId) {
	Entity* entity = new Entity();

	entity->set_id("test_id");
	EXPECT_EQ("test_id", entity->get_id());
}