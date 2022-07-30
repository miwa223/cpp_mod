#include "Span.hpp"

Span::Span(unsigned int n) : N(n), nums(0) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span	&Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	this->N = other.N;
	this->nums = other.nums;
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	assertion(ADD, 0);
	nums.push_back(n);
}

void	Span::addManyNumbers(const int *arr, size_t cnt)
{
	assertion(ADD_MANY, cnt);
	this->nums.insert(this->nums.begin() + this->nums.size(), arr, arr + cnt);
}

void	Span::addManyNumbers(const std::vector<int> &vec)
{
	assertion(ADD_MANY, vec.size());
	this->nums.insert(this->nums.begin() + this->nums.size(), vec.begin(), vec.end());
}

size_t	Span::shortestSpan()
{
	assertion(COMPARE, 0);

	size_t	shortest_span = std::numeric_limits<size_t>::max();
	std::sort(this->nums.begin(), this->nums.end());
	size_t	compared;
	for (size_t i = 1; i < this->nums.size(); i++)
	{
		compared = static_cast<size_t>(this->nums[i])
							- static_cast<size_t>(this->nums[i - 1]);
		if (compared < shortest_span)
			shortest_span = compared;
	}
	return (shortest_span);
}

size_t	Span::longestSpan()
{
	assertion(COMPARE, 0);

	std::sort(this->nums.begin(), this->nums.end());
	return (static_cast<size_t>(this->nums.back())
			- static_cast<size_t>(this->nums.front()));
}

void	Span::assertion(enum e_OPERATION type, size_t cnt) const
{
	if (type == ADD && this->nums.size() >= this->N)
		throw std::out_of_range("Error: Span size overflow");
	else if (type == ADD_MANY && (cnt > std::numeric_limits<uint>::max()
			|| this->nums.size() + cnt >= static_cast<size_t>(this->N)))
		throw std::out_of_range("Error: Cant't add all numbers");
	else if (type == COMPARE && this->nums.size() <= 1)
		throw std::runtime_error("Error: Comparison not found");
}
