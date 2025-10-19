#include "Zombie.hpp"

std::string Zombie::get_rnd_name(void)
{
	const std::string char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string rnd_name(10, '\0');
	std::string::iterator iter = rnd_name.begin();
	std::string::iterator end = rnd_name.end();

	while (iter != end)
	{
		*iter = char_set.at(static_cast<int>(Random::get_rnd_nbr_in_range(0.0, 25.0)));
		++iter;
	}
	return (rnd_name);
}

void Zombie::announce(void) const
{
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(const std::string& name)
{
	_name = name;
	announce();
}

Zombie::Zombie(void) {}

Zombie::Zombie(const std::string &name)
	: _name(name)
{
	announce();
}

Zombie::~Zombie(void)
{
	std::cout << "<" << _name << "> Destroyed" << std::endl;
}
