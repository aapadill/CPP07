/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 07:53:40 by aapadill          #+#    #+#             */
/*   Updated: 2026/02/05 18:20:53 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T, unsigned int N>
unsigned int	array_len(T (&)[N])
{
	return (N);
}

template <typename T>
void	print_value(const T &value)
{
	std::cout << value << " ";
}

void	increment_int(int &value)
{
	++value;
}

int	main(void)
{
	int			a[] = {1, 2, 3, 4};
	const int	b[] = {5, 6, 7};
	std::string	c[] = {"alpha", "beta", "gamma"};

	std::cout << "ints: ";
	iter(a, array_len(a), print_value<int>);
	std::cout << std::endl;

	iter(a, array_len(a), increment_int);
	std::cout << "ints after increment: ";
	iter(a, array_len(a), print_value<int>);
	std::cout << std::endl;

	std::cout << "const ints: ";
	iter(b, array_len(b), print_value<int>);
	std::cout << std::endl;

	std::cout << "strings: ";
	iter(c, array_len(c), print_value<std::string>);
	std::cout << std::endl;

	return (0);
}
