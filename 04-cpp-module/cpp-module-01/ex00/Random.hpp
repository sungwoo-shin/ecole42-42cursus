#ifndef RANDOM_HPP
#define RANDOM_HPP

class Random
{
private :
	static int seed;

	Random(void);
	~Random(void);

public :
	static double get_rnd_nbr(void);
	static double get_rnd_nbr_in_range(double min, double max);
};

#endif
