#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(void)
	{
		return (this->c.begin());
	}
	iterator end(void)
	{
		return (this->c.end());
	}

	MutantStack<T>& operator=(const MutantStack<T>& other);
	MutantStack(void);
	MutantStack(const MutantStack<T>& other);
	~MutantStack(void);
};

#endif

/*
** template<class T, Class C = deque<T> >
** class std::stack {
**
**     protected:
**
**         C c;
**
**     public:
**
**         typedef typename C::value_type value_type;
**
**         typedef typename C::size_type size_type;
**
**         typedef C container_type;
**
**         explicit stack(const C& a = C()) : c(a){} // Inherit the constructor
**
**         bool empty() const { return c.empty(); }
**
**         size_type size() const { return c.size(); }
**
**         value_type& top() const { return c.back(); }
**
**         const value_type& top() const { return c.back(); }
**
**         void push(const value_type& n) { c.push_back(n); }
**
**         void pop() { c.pop_back(); }
**
** };
**
** https://en.wikipedia.org/wiki/Stack_(C%2B%2B)
*/

/*
** typedef typename std::stack<T>::container_type::iterator
** 	iterator;
** typedef typename std::stack<T>::container_type::const_iterator
** 	const_iterator;
** typedef typename std::stack<T>::container_type::reverse_iterator
** 	reverse_iterator;
** typedef typename std::stack<T>::container_type::const_reverse_iterator
** 	const_reverse_iterator;
**
** iterator begin(void)
** {
** 	return (this->c.begin());
** }
**
** iterator end(void)
** {
** 	return (this->c.end());
** }
**
** const_iterator cbegin(void) const
** {
** 	return (this->c.cbegin());
** }
**
** const_iterator cend(void) const
** {
** 	return (this->c.cend());
** }
**
** reverse_iterator rbegin(void)
** {
** 	return (this->c.rbegin());
** }
**
** reverse_iterator rend(void)
** {
** 	return (this->c.rend());
** }
**
** const_reverse_iterator crbegin(void) const
** {
** 	return (this->c.crbegin());
** }
**
** const_reverse_iterator crend(void) const
** {
** 	return (this->c.crend());
** }
*/
