#pragma once

#include "npc.hpp"
#include "visitor.hpp"


class Knight : public NPC {
public:
    Knight(const std::string&, int, int);
    Knight(std::istream&);

    virtual bool accept(const std::shared_ptr<NPC>&) const override;

    void save(std::ostream&) override;

    friend std::ostream& operator<<(std::ostream&, Knight&);
};