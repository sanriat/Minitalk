/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   un_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:18:45 by damoncad          #+#    #+#             */
/*   Updated: 2024/02/09 15:40:37 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	un_digit(unsigned int n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	if (n == 0)
		return (write(1, "0", 1));
	else if (n < 10)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = un_digit(n / 10);
		return (count + un_digit(n % 10));
	}
}
