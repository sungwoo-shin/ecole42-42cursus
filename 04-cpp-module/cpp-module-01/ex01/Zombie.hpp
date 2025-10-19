#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include "Random.hpp"

# define NB_ZOMBIE 10

class Zombie
{
private :
	std::string _name;

	Zombie(void);

public :
	void announce(void) const;
	static Zombie *zombieHorde(int N);
	
	void set_name(const std::string &name);
	static std::string get_rnd_name(void);

	Zombie(const std::string& name);
	~Zombie(void);
};

#endif
