/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:54:46 by damoncad          #+#    #+#             */
/*   Updated: 2024/02/09 15:56:15 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(uintptr_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	put_ptr(uintptr_t n, int *count)
{
	if (n >= 16)
	{
		put_ptr(n / 16, count);
		put_ptr(n % 16, count);
	}
	else
	{
		if (n <= 9)
			*count += write (1, (char []){n + '0'}, 1);
		else
			*count += write (1, (char []){n - 10 + 'a'}, 1);
	}
}

int	print_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	put_ptr(ptr, &count);
	return (count);
}
