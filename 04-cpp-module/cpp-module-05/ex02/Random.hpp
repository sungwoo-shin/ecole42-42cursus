#ifndef RANDOM_HPP
#define RANDOM_HPP

class Random
{
private:
	static int seed;

	Random(void);
	~Random(void);

public:
	static double randv(void);
	static double randr(double min, double max);
};

#endif
