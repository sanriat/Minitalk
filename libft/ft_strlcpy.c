/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:47:02 by damoncad          #+#    #+#             */
/*   Updated: 2023/12/13 20:58:00 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	a;

	a = 0;
	if (size == 0)
	{
		while (src[a])
			a++;
		return (a);
	}
	while (a < size - 1 && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	if (a < size)
		dest[a] = '\0';
	while (src[a] != '\0')
		a++;
	return (a);
}
