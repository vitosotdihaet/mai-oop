#include <gtest/gtest.h>

#include "npc.hpp"
#include "elf.hpp"
#include "druid.hpp"
#include "knight.hpp"


class NPCTest : public testing::Test {
protected:
    void SetUp() override {
        elf = std::make_shared<Elf>("George", 0, 15);
        druid = std::make_shared<Druid>("John", 50, 15);
        knight = std::make_shared<Knight>("David", 100, 15);
    }

    std::shared_ptr<NPC> elf, druid, knight;
};

TEST_F(NPCTest, AcceptTest) {
    ASSERT_TRUE(elf->accept(knight));
    ASSERT_FALSE(druid->accept(knight));
    ASSERT_FALSE(knight->accept(knight));

    ASSERT_FALSE(elf->accept(elf));
    ASSERT_TRUE(druid->accept(elf));
    ASSERT_TRUE(knight->accept(elf));

    ASSERT_FALSE(elf->accept(druid));
    ASSERT_TRUE(druid->accept(druid));
    ASSERT_FALSE(knight->accept(druid));
}

TEST_F(NPCTest, IsCloseTest) {
    ASSERT_TRUE(elf->is_close(druid, 50));
    ASSERT_TRUE(elf->is_close(knight, 100));
    ASSERT_FALSE(elf->is_close(druid, 25));
    ASSERT_FALSE(elf->is_close(knight, 50));
}