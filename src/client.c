/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:14:42 by soutin            #+#    #+#             */
/*   Updated: 2023/09/30 18:12:30 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	g_synchro;

void	send_null_char(pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (kill(pid, SIGUSR1) < 0)
			exit(1);
		while (!g_synchro)
			usleep(10);
		g_synchro = 0;
	}
}

void	send_signals(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (i < 8)
		{
			if (!((str[j] >> i) & 1))
			{
				if (kill(pid, SIGUSR1) < 0)
					exit(1);
			}	
			else
				if (kill(pid, SIGUSR2) < 0)
					exit(1);
			while (!g_synchro)
				usleep(10);
			g_synchro = 0;
			i++;
		}
		j++;
	}
	send_null_char(pid);
}

void	received_message(int signum)
{
	if (signum == 10)
	{
		ft_putstr_fd("OK", 1);
		exit(0);
	}
}

void	ft_synchro(int signum)
{
	if (signum == 12)
		g_synchro = 1;
}

int	main(int c, char **v)
{
	int	server;

	if (c == 3)
	{
		signal(SIGUSR1, received_message);
		signal(SIGUSR2, ft_synchro);
		server = ft_atoi(v[1]);
		if (server < 0)
			return (ft_printf("invalid pid"), 1);
		send_signals(server, v[2]);
		while (1)
			pause();
	}
	else
		ft_printf("./client [server PID] [string to send]");
	return (0);
}
