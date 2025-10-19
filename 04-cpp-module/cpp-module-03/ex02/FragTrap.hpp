#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

# define F_NAME	"FragTrap"
# define F_HP	100
# define F_EP	100
# define F_AD	30

class FragTrap : public ClapTrap
{
public :
	void hiFivesGuys(void) const;

	FragTrap &operator=(const FragTrap &f);
	FragTrap(void);
	explicit FragTrap(const std::string &name);
	FragTrap(const FragTrap &f);
	virtual ~FragTrap(void);
};

#endif
