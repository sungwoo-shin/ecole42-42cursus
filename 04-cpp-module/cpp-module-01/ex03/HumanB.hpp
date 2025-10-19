#ifndef HUMANB_HPP_
# define HUMANB_HPP_

# include <string>
# include "Weapon.hpp"

class HumanB
{
private :
	std::string _name;
	Weapon *_w;

	HumanB(void);

public :
	void setWeapon(Weapon *w);
	void attack(void) const;

	explicit HumanB(const std::string &name);
	~HumanB(void);
};

#endif
