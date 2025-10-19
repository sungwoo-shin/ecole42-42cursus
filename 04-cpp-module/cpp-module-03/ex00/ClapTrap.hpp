#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iomanip>
# include <iostream>

# define W_SIZE	12
# define C_NAME	"ClapTrap"
# define C_HP	10
# define C_EP	10
# define C_AD	0

class ClapTrap
{
private :
	std::string _name;
	unsigned int _hp; // hitpoints
	unsigned int _ep; // energy points
	unsigned int _ad; // attack damage

	const std::string _class_name;
	const unsigned int _class_hp;
	const unsigned int _class_ep;
	const unsigned int _class_ad;

public :
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void print_status(std::ostream &o) const;

	void setName(const std::string &name);
	void setHP(unsigned int *hp);
	void setEP(unsigned int *ep);
	void setAD(unsigned int *ad);

	std::string getName(void) const;
	unsigned int getHP(void) const;
	unsigned int getEP(void) const;
	unsigned int getAD(void) const;

	void setClassName(const std::string &name);
	void setClassHP(const unsigned int *hp);
	void setClassEP(const unsigned int *ep);
	void setClassAD(const unsigned int *ad);

	std::string getClassName(void) const;
	unsigned int getClassHP(void) const;
	unsigned int getClassEP(void) const;
	unsigned int getClassAD(void) const;

	ClapTrap &operator=(const ClapTrap &c);

	ClapTrap(void);
	ClapTrap(const ClapTrap &c);
	explicit ClapTrap(const std::string &name);
	~ClapTrap(void);
};

#endif
