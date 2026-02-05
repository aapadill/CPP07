/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:02:35 by aapadill          #+#    #+#             */
/*   Updated: 2026/02/05 21:30:10 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
	private:
		T				*_data;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		~Array(void);

		Array	&operator=(const Array &other);

		T			&operator[](unsigned int index);
		const T		&operator[](unsigned int index) const;
		unsigned int	size(void) const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Array index out of bounds");
				}
		};
};

//default constructor
template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0)
{
}

//constructor //array initializer
template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (n > 0)
		_data = new T[n]();
}

//copy constructor
template <typename T>
Array<T>::Array(const Array &other) : _data(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_data = new T[_size]();
		unsigned int	i = 0;

		while (i < _size)
		{
			_data[i] = other._data[i];
			i++;
		}
	}
}

//destructor
template <typename T>
Array<T>::~Array(void)
{
	delete [] _data;
}

//op= overload
template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		T	*new_data = NULL;

		if (other._size > 0)
		{
			new_data = new T[other._size]();
			unsigned int	i = 0;

			while (i < other._size)
			{
				new_data[i] = other._data[i];
				i++;
			}
		}
		delete [] _data;
		_data = new_data;
		_size = other._size;
	}
	return (*this);
}

//op[] overload //mutable elements (non-const)
template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_data[index]);
}

//op[] overload //const elements
template <typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_data[index]);
}

//array size getter
template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

#endif
