#include "mutantstack.hpp"

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other)
		this->c = other.c;
	return (*this);
}

template <typename T>
MutantStack<T>::MutantStack(void)
	: std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other)
	: std::stack<T>(other)
{}

template <typename T>
MutantStack<T>::~MutantStack() {}
