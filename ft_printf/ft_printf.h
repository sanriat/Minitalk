/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:28 by damoncad          #+#    #+#             */
/*   Updated: 2024/02/09 15:49:55 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		print_char(int c);
int		print_mod(void);
int		print_str(char *str);
int		print_hex(unsigned int n, const char specifier);
int		print_ptr(unsigned long long ptr);
int		un_digit(unsigned int n);
int		print_digit(long n);

#endif