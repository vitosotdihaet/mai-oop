#pragma once

#include "npc.hpp"
#include "visitor.hpp"


class Druid : public NPC {
public:
    Druid(const std::string&, int, int);
    Druid(std::istream&);

    virtual bool accept(const std::shared_ptr<NPC>&) const override;

    void save(std::ostream&) override;

    friend std::ostream& operator<<(std::ostream&, Druid&);
};