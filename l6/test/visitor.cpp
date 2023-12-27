#include <gtest/gtest.h>

#include "npc.hpp"
#include "elf.hpp"
#include "druid.hpp"
#include "knight.hpp"
#include "visitor.hpp"


class VisitorTest : public testing::Test {
protected:
    void SetUp() override {
        elf = std::make_shared<Elf>("George", 0, 15);
        druid = std::make_shared<Druid>("John", 50, 15);
        knight = std::make_shared<Knight>("David", 100, 15);

        elf_visitor = std::make_shared<ElfVisitor>();
        druid_visitor = std::make_shared<DruidVisitor>();
        knight_visitor = std::make_shared<KnightVisitor>();
    }

    std::shared_ptr<NPC> elf, druid, knight;
    std::shared_ptr<Visitor> elf_visitor, druid_visitor, knight_visitor;
};

TEST_F(VisitorTest, VisitTest) {
    ASSERT_TRUE(knight_visitor->visit(std::static_pointer_cast<Elf>(elf)));
    ASSERT_FALSE(knight_visitor->visit(std::static_pointer_cast<Druid>(druid)));
    ASSERT_FALSE(knight_visitor->visit(std::static_pointer_cast<Knight>(knight)));

    ASSERT_FALSE(elf_visitor->visit(std::static_pointer_cast<Elf>(elf)));
    ASSERT_TRUE(elf_visitor->visit(std::static_pointer_cast<Druid>(druid)));
    ASSERT_TRUE(elf_visitor->visit(std::static_pointer_cast<Knight>(knight)));

    ASSERT_FALSE(druid_visitor->visit(std::static_pointer_cast<Elf>(elf)));
    ASSERT_TRUE(druid_visitor->visit(std::static_pointer_cast<Druid>(druid)));
    ASSERT_FALSE(druid_visitor->visit(std::static_pointer_cast<Knight>(knight)));
}

