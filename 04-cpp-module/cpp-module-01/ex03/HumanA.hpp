#ifndef HUMANA_HPP_
# define HUMANA_HPP_

# include <string>
# include "Weapon.hpp"

class HumanA
{
private :
	std::string _name;
	Weapon &_w;

public :
	void attack(void) const;

	HumanA(const std::string &name, Weapon *w);
	~HumanA(void);
};

#endif
