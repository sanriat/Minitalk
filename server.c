/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-17 14:37:23 by damoncad          #+#    #+#             */
/*   Updated: 2024-05-17 14:37:23 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sec_assist(t_minitalk *minitalk)
{
	char	*new_str;

	new_str = malloc(minitalk->len + 2);
	if (!new_str)
	{
		ft_printf("Error: Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	if (minitalk->str)
		ft_memcpy(new_str, minitalk->str, minitalk->len);
	new_str[minitalk->len] = minitalk->data;
	new_str[minitalk->len + 1] = '\0';
	free(minitalk->str);
	minitalk->str = new_str;
	minitalk->len++;
	if (kill(minitalk->pid, SIGUSR1) == -1)
	{
		ft_printf("Error: Failed to send acknowledgment\n");
		exit(EXIT_FAILURE);
	}
}

void	assist(t_minitalk *minitalk)
{
	ft_printf("Received message: %s\n", minitalk->str);
	free(minitalk->str);
	minitalk->str = NULL;
	minitalk->len = 0;
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static int			bit_count = 0;
	static t_minitalk	minitalk = {0, 0, 0, NULL, 0};

	(void)context;
	(void)info;
	if (info->si_pid)
		minitalk.pid = info->si_pid;
	if (signum == SIGUSR1)
		minitalk.data &= ~(1 << bit_count);
	else if (signum == SIGUSR2)
		minitalk.data |= 1 << bit_count;
	bit_count++;
	if (bit_count == 8)
	{
		if (minitalk.data == '\0')
		{
			assist(&minitalk);
		}
		else
			sec_assist(&minitalk);
		bit_count = 0;
		minitalk.data = 0;
	}
}

int	main(void)
{
	struct sigaction	server;

	server.sa_sigaction = server_handler;
	server.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&server.sa_mask);
	if (sigaction(SIGUSR1, &server, NULL) == -1
		|| sigaction(SIGUSR2, &server, NULL) == -1)
	{
		ft_printf("Error: Failed to register signal handler\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
