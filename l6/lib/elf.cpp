#include "elf.hpp"


Elf::Elf(const std::string& name, int x, int y) : NPC(ElfType, name, x, y) {}
Elf::Elf(std::istream& is) : NPC(ElfType, is) {}

bool Elf::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->type);
    std::shared_ptr<Elf> defender = std::dynamic_pointer_cast<Elf>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Elf::save(std::ostream& os) {
    os << ElfType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Elf& elf) {
    os << "elf " << *static_cast<NPC*>(&elf) << std::endl;
    return os;
}