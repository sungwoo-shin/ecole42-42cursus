#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
	unsigned int _n;
	std::vector<int> _vec;
	Span(void);

public:
	void addNumber(int num);
	void addNumber(std::vector<int>::iterator const &begin,
			std::vector<int>::iterator const &end);
	int shortestSpan(void) const;
	int longestSpan(void) const;

	Span& operator=(const Span& other);
	Span(unsigned int n);
	Span(const Span& other);
	~Span(void);
};

#endif
