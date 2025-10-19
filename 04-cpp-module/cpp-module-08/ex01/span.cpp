#include "span.hpp"

void Span::addNumber(int num)
{
	if (_vec.size() == _n)
		throw std::runtime_error("Span is already full!");
	_vec.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator const &begin,
			std::vector<int>::iterator const &end)
{
	std::vector<int>::iterator iter = begin;

	while (iter != end)
	{
		if (_vec.size() == _n)
			throw std::runtime_error("Span is already full!");
		_vec.push_back(*iter);
		++iter;
	}
}

int Span::shortestSpan(void) const
{
	if (_vec.empty() || _vec.size() == 1)
		throw std::runtime_error("Span is empty or contains only one element!");
	std::vector<int> copy = _vec;
	std::sort(copy.begin(), copy.end());

	int min_span = INT_MAX;
	int prev = *copy.begin();
	for (std::vector<int>::iterator iter = copy.begin() + 1; iter != copy.end(); ++iter)
	{
		min_span = std::min(min_span, *iter - prev);
		prev = *iter;
	}
	return (min_span);
}

int Span::longestSpan(void) const
{
	if (_vec.empty() || _vec.size() == 1)
		throw std::runtime_error("Span is empty or contains only one element!");
	std::vector<int> copy = _vec;
	std::sort(copy.begin(), copy.end());
	return (copy.back() - copy.front());
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_n = other._n;
		_vec = other._vec;
	}
	return (*this);
}

Span::Span(void)
	: _n(0)
{}

Span::Span(unsigned int n)
	: _n(n)
{}

Span::Span(const Span& other)
	: _n(other._n), _vec(other._vec)
{}

Span::~Span() {}
