#include <iostream>
#include <cstdlib> //for rand, srand
#include <ctime> //for time
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

static int	test_empty_array(void)
{
    Array<int> empty;
    std::cout << "empty size: " << empty.size() << std::endl;
    try
    {
        empty[0] = 42;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

static int	test_mirror_values(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete [] mirror;
            return 1;
        }
    }
    delete [] mirror;
    return 0;
}

static int	test_copy_constructor(void)
{
    Array<int> numbers(3);

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    Array<int> copy(numbers);
    numbers[0] = 42;
    if (copy[0] != 1)
    {
        std::cerr << "copy isn't independent!!" << std::endl;
        return 1;
    }
    return 0;
}

static int	test_assignment_operator(void)
{
    Array<int> numbers(3);
    Array<int> assigned;

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    assigned = numbers;
    numbers[1] = 42;
    if (assigned[1] != 2)
    {
        std::cerr << "assignment isn't independent!!" << std::endl;
        return 1;
    }
    return 0;
}

static void	test_const_access(void)
{
    Array<int> numbers(3);

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    const Array<int> const_numbers(numbers);

    std::cout << "const access: " << const_numbers[2] << std::endl;
}

static void	test_bounds(void)
{
    Array<int> numbers(3);

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
}

static void	test_strings(void)
{
    Array<std::string> words(3);

    words[0] = "alpha";
    words[1] = "beta";
    words[2] = "gamma";
    std::cout << "words: " << words[0] << " " << words[1] << " " << words[2] << std::endl;
}

int main(int, char**)
{
    srand(time(NULL));
    if (test_empty_array() != 0)
        return 1;
    if (test_mirror_values() != 0)
        return 1;
    if (test_copy_constructor() != 0)
        return 1;
    if (test_assignment_operator() != 0)
        return 1;
    test_const_access();
    test_bounds();
    test_strings();

    return 0;
}
