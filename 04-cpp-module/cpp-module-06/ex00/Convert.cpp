#include "Convert.hpp"
#include <cctype>

char Convert::toChar(void) const
{
	return (static_cast<char>(_value));
}

int Convert::toInt(void) const
{
	return (static_cast<int>(_value));
}

float Convert::toFloat(void) const
{
	return (static_cast<float>(_value));
}

double Convert::toDouble(void) const
{
	return (static_cast<double>(_value));
}

const double& Convert::getValue(void) const
{
	return (_value);
}

const std::string& Convert::getInput(void) const
{
	return (_input);
}

Convert& Convert::operator=(const Convert& c)
{
	if (this != &c)
	{
		*(const_cast<std::string*>(&_input)) = c.getInput();
		*(const_cast<double*>(&_value)) = c.getValue();
	}
	return (*this);
}

Convert::Convert(void)
	: _input(""), _value(0.0)
{}

Convert::Convert(const std::string& input)
	: _input(input), _value(0.0)
{
	*(const_cast<double*>(&_value)) = std::stod(_input);
}

Convert::Convert(const Convert& c)
	: _input(c.getInput()), _value(c.getValue())
{}

Convert::~Convert(void) {}

static void printToChar(std::ostream& o, const Convert& c)
{
	o << "char: ";
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
	{
		o << C_NP << std::endl;
	}
	else if (std::isprint(c.toChar()))
	{
		o << "'" << c.toChar() << "'" << std::endl;
	}
	else
	{
		o << C_ND << std::endl;
	}
}

static void printToInt(std::ostream& o, const Convert& c)
{
	o << "int: ";
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
	{
		o << C_NP << std::endl;
	}
	else
	{
		o << c.toInt() << std::endl;
	}
}

static void printToReal(std::ostream& o, const Convert& c)
{
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
	{
		o << "float: " << std::showpos << c.toFloat() << "f" << std::endl;
		o << "double: " << std::showpos << c.toDouble() << std::endl;
		return ;
	}

	if (c.toFloat() == static_cast<int>(c.toFloat()))
	{
		o << "float: " << c.toFloat() << ".0f" << std::endl;
	}
	else
	{
		o << "float: " << c.toFloat() << "f" << std::endl;
	}

	if (c.toDouble() == static_cast<int>(c.toDouble()))
	{
		o << "double: " << c.toDouble() << ".0" << std::endl;
	}
	else
	{
		o << "double: " << c.toDouble() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, const Convert& c)
{
	printToChar(o, c);
	printToInt(o, c);
	printToReal(o, c);
	return (o);
}
