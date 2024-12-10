/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:43:16 by damoncad          #+#    #+#             */
/*   Updated: 2024/02/04 16:23:16 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (str != NULL)
	{
		while (*str != '\0')
		{
			print_char(((int)*str));
			++count;
			++str;
		}
	}
	else
		return (write(1, "(null)", 6));
	return (count);
}
