#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <set>
#include <cmath>
#include <mutex>


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
    std::mutex mtx;

    NPCType type;
    std::string name{""};
    std::pair<int, int> position = { 0, 0 };
    bool alive = true;
    int kill_distance = 0;

    std::vector<std::shared_ptr<Observer>> observers;

public:
    NPC(NPCType, const std::string&, int, int);
    NPC(NPCType, std::istream&);

    NPCType get_type();

    virtual bool accept(const std::shared_ptr<NPC>&) const = 0;

    void subscribe(const std::shared_ptr<Observer>&);
    void fight_notify(const std::shared_ptr<NPC>, bool) const;
    virtual bool is_close(const std::shared_ptr<NPC>&);

    virtual void save(std::ostream&);

    friend std::ostream& operator<<(std::ostream&, NPC&);

    std::pair<int, int> get_position();

    virtual int get_move_distance() {
        return 0;
    }

    void move(int, int, int, int);

    bool is_alive();
    void must_die();

    int throw_dice() const noexcept;
};