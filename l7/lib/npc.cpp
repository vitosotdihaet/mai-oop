#include "npc.hpp"


NPC::NPC(NPCType t, const std::string& _name, int _x, int _y) : type(t), name(_name), position(_x, _y) {}
NPC::NPC(NPCType t, std::istream& is) : type(t) {
    is >> name;
    is >> position.first;
    is >> position.second;
}

void NPC::subscribe(const std::shared_ptr<Observer>& obs) {
    observers.push_back(obs);
}

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win) const {
    for (auto& o : observers)
        o->on_fight(std::const_pointer_cast<NPC>(shared_from_this()), defender, win);
}

bool NPC::is_close(const std::shared_ptr<NPC>& other) {
    auto [other_x, other_y] = other->position;

    std::lock_guard<std::mutex> lock(mtx);

    if ((std::pow(position.first - other_x, 2) + std::pow(position.second - other_y, 2)) <= std::pow(kill_distance, 2))
        return true;
    else
        return false;
}

NPCType NPC::get_type() {
    std::lock_guard<std::mutex> lock(mtx);
    return type;
}

void NPC::save(std::ostream& os) {
    os << name << std::endl;
    os << position.first << std::endl;
    os << position.second << std::endl;
}

std::ostream& operator<<(std::ostream& os, NPC& npc) {
    os << npc.name << ": position: {" << npc.position.first << ", " << npc.position.second << "}";
    return os;
}

std::pair<int, int> NPC::get_position() {
    std::lock_guard<std::mutex> lock(mtx);
    return position;
}

void NPC::move(int shift_x, int shift_y, int max_x, int max_y) {
    std::lock_guard<std::mutex> lock(mtx);
    auto [x, y] = position;
    int move_distance = get_move_distance();

    if (shift_x > move_distance || shift_y > move_distance) {
        throw std::runtime_error("Max move distance is " + move_distance);
    }

    if ((x + shift_x >= 0) && (x + shift_x <= max_x)) x += shift_x;
    if ((y + shift_y >= 0) && (y + shift_y <= max_y)) y += shift_y;

    position = { x, y };
}

bool NPC::is_alive() {
    std::lock_guard<std::mutex> lock(mtx);
    return alive;
}

void NPC::must_die() {
    std::lock_guard<std::mutex> lock(mtx);
    alive = false;
}

int NPC::throw_dice() const noexcept {
    return std::rand() % 6 + 1;
}