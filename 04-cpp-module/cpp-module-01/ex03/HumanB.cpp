#include "HumanB.hpp"
#include "Color.hpp"

void HumanB::setWeapon(Weapon *w)
{
	_w = w;
}

void HumanB::attack(void) const
{
	std::cout << "[ " << _name << " ] ";
	if (_w)
		std::cout << BLU << "attacks" << " with his " << _w->getType() << EOC
		<< std::endl;
	else
		std::cout << BYEL << "has no weapon" << EOC << std::endl;
}

HumanB::HumanB(void) {}

HumanB::HumanB(const std::string &name)
	: _name(name), _w(NULL)
{
	std::cout << "[ " << _name << " ] "
	<< "is " << GRN << "respawned" << EOC << " without any Weapon"
	<< std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "[ " << _name << " ] "
	<< "is " << RED << "dead" << EOC << std::endl;
}
