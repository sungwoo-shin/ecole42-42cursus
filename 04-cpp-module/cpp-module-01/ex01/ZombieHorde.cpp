#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N)
{
	Zombie *z = new Zombie[N];

	for (int i = 0; i < N; ++i)
		z[i].set_name(Zombie::get_rnd_name());
	return (z);
}
