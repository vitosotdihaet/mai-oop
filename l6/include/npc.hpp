#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <set>
#include <cmath>


class NPC;
class Elf;
class Druid;
class Knight;


using set_t = std::set<std::shared_ptr<NPC>>;


enum NPCType {
    UnknownType,
    ElfType,
    DruidType,
    KnightType,
};


class Observer {
public:
    virtual void on_fight(const std::shared_ptr<NPC>, const std::shared_ptr<NPC>, bool) = 0;
};


class Visitor;


class NPC : public std::enable_shared_from_this<NPC> {
protected:
    std::string name { "" };
    int x { 0 };
    int y { 0 };
    std::vector<std::shared_ptr<Observer>> observers;

public:
    NPCType type;
    NPC(NPCType, const std::string&, int, int);
    NPC(NPCType, std::istream&);

    virtual bool accept(const std::shared_ptr<NPC>&) const = 0;

    void subscribe(const std::shared_ptr<Observer>&);
    void fight_notify(const std::shared_ptr<NPC>, bool) const;
    virtual bool is_close(const std::shared_ptr<NPC>&, size_t) const;

    virtual void save(std::ostream&);

    friend std::ostream& operator<<(std::ostream&, NPC&);
};