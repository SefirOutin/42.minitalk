/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:35:41 by soutin            #+#    #+#             */
/*   Updated: 2023/09/30 18:04:23 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	tab[8] = {1, 2, 4, 8, 16, 32, 64, 128};
	static int	i;
	pid_t		client_pid;
	static int	c;

	(void)context;
	client_pid = info->si_pid;
	if ((i < 8) && signum == SIGUSR2)
		c += tab[i];
	i++;
	if (i == 8)
	{
		i = 0;
		if (!c)
		{
			if (kill(client_pid, SIGUSR1) < 0)
				exit(1);
			ft_printf("\nServer PID : %d\n", client_pid);
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
	if (kill(client_pid, SIGUSR2) < 0)
		exit(1);
}

void	close_process(int signum)
{
	if (signum == 2)
		exit(0);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT);
	pid = getpid();
	ft_printf("%d", pid);
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	signal(SIGINT, &close_process);
	while (1)
		pause();
	return (0);
}
