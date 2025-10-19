#include "Base.hpp"

Base* generate(void)
{
	int opt = static_cast<int>(Random::randr(0.0, 10.0)) / 3;

	switch (opt)
	{
		case 0:
			std::cout << "Instanciate A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Instanciate B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Instanciate C" << std::endl;
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

static bool try_cast(const Base& p, const std::string& s)
{
	try
	{
		if (s == "A")
			static_cast<void>(dynamic_cast<const A&>(p));
		else if (s == "B")
			static_cast<void>(dynamic_cast<const B&>(p));
		else if (s == "C")
			static_cast<void>(dynamic_cast<const C&>(p));
		std::cout << s << std::endl;
	}
	catch (std::exception&) {}
	return (false);
}

/*
** https://www.ibm.com/docs/en/i/7.2?topic=operator-dynamic-casts-references
*/

void identify(const Base& p)
{
	if (try_cast(p, "A") || try_cast(p, "B") || try_cast(p, "C"))
		return ;
}
