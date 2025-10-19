#ifndef BASE_HPP
#define BASE_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Random.hpp"

class Base
{
public:
	virtual ~Base(void) {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(const Base& p);

#endif
