#include <iostream>
#include "Array.tpp"

#define MAX_VAL 750

class Sample
{
	public:
		Sample(size_t n = 0);
		~Sample();
		size_t	get_num() const;
		void	set_num(size_t num);
	private:
		size_t	num;
};

void	test_default_constructor();
void	test_complex_type();

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	/*
	test_default_constructor();
	test_complex_type();
	*/
    return 0;
}

void	test_default_constructor()
{
	Array<int> a;
	try
	{
		std::cout << "test_default_constructor: " << a[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test_complex_type()
{
	Array<Sample> A(5);

	for (size_t i = 0; i < A.size(); i++)
	{
		A[i].set_num(i + 1);
	}
	for (size_t i = 0; i < A.size(); i++)
	{
		std::cout << A[i].get_num();
	}
	std::cout << std::endl;
}

Sample::Sample(size_t n) : num(n) {}

Sample::~Sample() {}

size_t Sample::get_num() const
{
	return (this->num);
}

void Sample::set_num(size_t num)
{
	this->num = num;
}
