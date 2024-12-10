/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-17 14:37:32 by damoncad          #+#    #+#             */
/*   Updated: 2024-05-17 14:37:32 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int dest_pid, char c)
{
	int		i;
	char	bit;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if ((int)bit == 0)
		{
			if (kill(dest_pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else if ((int)bit == 1)
		{
			if (kill(dest_pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		usleep(200);
		i++;
	}
}

void	send_message(int dest_pid, const char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		send_char(dest_pid, message[i]);
		i++;
	}
	send_char(dest_pid, '\0');
}

void	client_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		ft_printf("received signal from server, pid: %d\n", info->si_pid);
	else if (signum == SIGUSR2)
	{
		ft_printf("end message signal %d\n", info->si_pid);
		exit(EXIT_SUCCESS);
	}
}

void	config(struct sigaction *act)
{
	if (sigaction(SIGUSR1, act, NULL) < 0)
		exit(0);
	if (sigaction(SIGUSR2, act, NULL) < 0)
		exit(0);
}

int	main(int ac, char *av[])
{
	int					dest_pid;
	struct sigaction	client;

	if (ac != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", av[0]);
		exit(EXIT_FAILURE);
	}
	sigemptyset(&client.sa_mask);
	client.sa_flags = SA_RESTART | SA_SIGINFO;
	client.sa_sigaction = client_handler;
	config(&client);
	dest_pid = ft_atoi(av[1]);
	if (dest_pid <= 0)
	{
		ft_printf("Invalid PID: %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	ft_printf("Sending message \"%s\" to PID %d\n", av[2], dest_pid);
	send_message(dest_pid, av[2]);
	ft_printf("Message sent successfully!\n");
	return (0);
}
