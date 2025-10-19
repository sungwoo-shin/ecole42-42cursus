#ifndef WEAPON_HPP_
# define WEAPON_HPP_

# include <iostream>
# include <string>

class Weapon
{
private :
	std::string _type;

	Weapon(void);

public :
	const std::string &getType(void) const;
	void setType(const std::string &type);

	explicit Weapon(const std::string &type);
	~Weapon(void);
};

#endif
