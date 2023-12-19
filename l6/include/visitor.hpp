#pragma once

#include "npc.hpp"
#include "elf.hpp"
#include "druid.hpp"
#include "knight.hpp"


class Visitor {
public:
    virtual bool visit(const std::shared_ptr<Elf>&) const = 0;
    virtual bool visit(const std::shared_ptr<Druid>&) const = 0;
    virtual bool visit(const std::shared_ptr<Knight>&) const = 0;
};


class ElfVisitor final : public Visitor {
public:
    virtual bool visit(const std::shared_ptr<Elf>&) const override { return false; }
    virtual bool visit(const std::shared_ptr<Druid>&) const override { return true; }
    virtual bool visit(const std::shared_ptr<Knight>&) const override { return true; }
};

class DruidVisitor final : public Visitor {
    virtual bool visit(const std::shared_ptr<Elf>&) const override { return false; }
    virtual bool visit(const std::shared_ptr<Druid>&) const override { return true; }
    virtual bool visit(const std::shared_ptr<Knight>&) const override { return false; }
};

class KnightVisitor final : public Visitor {
    virtual bool visit(const std::shared_ptr<Elf>&) const override { return true; }
    virtual bool visit(const std::shared_ptr<Druid>&) const override { return false; }
    virtual bool visit(const std::shared_ptr<Knight>&) const override { return false; }
};


class VisitorFactory {
public:
    static std::shared_ptr<Visitor> CreateVisitor(const NPCType& type) {
        std::shared_ptr<Visitor> result;

        switch (type) {
            case NPCType::ElfType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<ElfVisitor>());
                break;

            case NPCType::DruidType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<DruidVisitor>());
                break;

            case NPCType::KnightType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<KnightVisitor>());
                break;

            default:
                break;
        }

        return result;
    }
};