/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-10 09:28:27 by damoncad          #+#    #+#             */
/*   Updated: 2024-05-10 09:28:27 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <limits.h>
# include <string.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_minitalk
{
	int		bits;
	int		data;
	int		len;
	char	*str;
	int		pid;
}	t_minitalk;

//server.c
void	send_ack(int dest_pid, int signum);
void	sec_assist(t_minitalk *minitalk);
void	assist(t_minitalk *minitalk);
void	server_handler(int signum, siginfo_t *info, void *context);
//client.c
void	send_char(int dest_pid, char c);
void	send_message(pid_t dest_pid, const char *message);
void	client_handler(int signum, siginfo_t *info, void *context);
void	config(struct sigaction *act);

#endif