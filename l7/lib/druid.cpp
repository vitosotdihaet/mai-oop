#include "druid.hpp"


Druid::Druid(const std::string& name, int x, int y) : NPC(DruidType, name, x, y) {}
Druid::Druid(std::istream& is) : NPC(DruidType, is) {}

bool Druid::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Druid> defender = std::dynamic_pointer_cast<Druid>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Druid::save(std::ostream& os) {
    os << DruidType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Druid& druid) {
    os << "druid " << *static_cast<NPC*>(&druid) << std::endl;
    return os;
}