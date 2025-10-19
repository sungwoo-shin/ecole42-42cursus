#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

# define S_NAME	"ScavTrap"
# define S_HP	100
# define S_EP	50
# define S_AD	20

class ScavTrap : public ClapTrap
{
public :
	void attack(const std::string &target);
	void guardGate(void) const;

	ScavTrap &operator=(const ScavTrap &s);

	ScavTrap(void);
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &s);
	virtual ~ScavTrap(void);
};

#endif
