#include "Random.hpp"

int Random::seed = 0;

double Random::get_rnd_nbr(void)
{
	seed = (seed * 1103515245 + 12345) & 0x7fffffff;
	return (static_cast<double>(seed) / static_cast<double>(0x80000000));
}

double Random::get_rnd_nbr_in_range(double min, double max)
{
	return ((get_rnd_nbr() * (max - min)) + min);
}

Random::Random(void) {}

Random::~Random(void) {}
