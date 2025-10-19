#include "HumanA.hpp"
#include "Color.hpp"

void HumanA::attack(void) const
{
	std::cout << "[ " << _name << " ] "
	<< "attacks" << " with his " << _w.getType()
	<< std::endl;
}

HumanA::HumanA(const std::string &name, Weapon *w)
	: _name(name), _w(*w)
{
	std::cout << "[ " << _name << " ] "
	<< "is " << GRN << "respawned" << EOC << " with " << _w.getType()
	<< std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "[ " << _name << " ] "
	<< "is " << RED << "dead" << EOC
	<< std::endl;
}
