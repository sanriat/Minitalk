/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:14:35 by damoncad          #+#    #+#             */
/*   Updated: 2024/02/09 15:52:36 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	hexa(unsigned int n, const char specifier)
{
	if (n >= 16)
	{
		hexa(n / 16, specifier);
		hexa(n % 16, specifier);
	}
	else
	{
		if (n <= 9)
			print_char((int)(n + '0'));
		else
		{
			if (specifier == 'x')
				print_char((int)(n - 10 + 'a'));
			if (specifier == 'X')
				print_char((int)(n - 10 + 'A'));
		}
	}
}

int	print_hex(unsigned int n, const char specifier)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		hexa(n, specifier);
	return (hexa_len(n));
}
