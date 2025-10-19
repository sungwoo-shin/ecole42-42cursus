#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cmath>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#define C_ND		"Non displayable"
#define C_NP		"impossible"

class Convert
{
private:
	const std::string _input;
	const double _value;

	Convert(void);

public:
	char toChar(void) const;
	int toInt(void) const;
	float toFloat(void) const;
	double toDouble(void) const;

	bool getError(void) const;
	const double& getValue(void) const;
	const std::string& getInput(void) const;

	Convert& operator=(const Convert& c);
	explicit Convert(const std::string& input);
	Convert(const Convert& c);
	~Convert(void);
};

std::ostream& operator<<(std::ostream& o, const Convert& c);

#endif
