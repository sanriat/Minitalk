/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:08:46 by damoncad          #+#    #+#             */
/*   Updated: 2024/02/09 15:37:40 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_digit(-n) + 1);
	}
	else if (n < 10)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_digit(n / 10);
		return (count + print_digit(n % 10));
	}
}
