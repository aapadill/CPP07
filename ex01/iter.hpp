/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:09:24 by aapadill          #+#    #+#             */
/*   Updated: 2026/02/05 18:38:05 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F>
void	iter(T *array, const unsigned int len, F func)
{
	unsigned int	i = 0;

	while (i < len)
		func(array[i++]);
}

#endif
