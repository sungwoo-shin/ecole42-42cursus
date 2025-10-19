#include "Weapon.hpp"
#include "Color.hpp"

const std::string &Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(const std::string &type)
{
	std::cout << "[ Weapon Type ] is changed " << _type;
	_type = type;
	std::cout << " to " << _type << std::endl;
}

Weapon::Weapon(void) {}

Weapon::Weapon(const std::string &type)
	: _type(type)
{
	std::cout << "[ Weapon Type ] "  << _type
	<< " is " << GRN << "generated" << EOC << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "[ Weapon Type ] " << _type
	<< " is " << RED << "broken" << EOC << std::endl;
}
