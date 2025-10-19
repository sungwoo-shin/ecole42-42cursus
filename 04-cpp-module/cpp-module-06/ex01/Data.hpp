#ifndef DATA_HPP
#define DATA_HPP

#include <cstdint>
#include <string>
#include <iostream>

class Data
{
private:
	std::string _model;
	int _serial;
	double _price;
	float _weight;

public:
	const std::string& getModel(void) const;
	const int& getSerial(void) const;
	const double& getPrice(void) const;
	const float& getWeight(void) const;

	Data& operator=(const Data& d);
	Data(void);
	Data(const std::string& model, int serial, double price, float weight);
	Data(const Data& d);
	~Data(void);
};

std::ostream& operator<<(std::ostream& o, const Data& ptr);
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
void print_spec(uintptr_t raw);

#endif
