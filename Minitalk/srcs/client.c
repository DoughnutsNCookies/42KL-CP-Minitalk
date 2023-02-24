/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:48:38 by schuah            #+#    #+#             */
/*   Updated: 2023/02/24 12:21:07 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_msg;

void	sig(int signo, siginfo_t *info, void *content)
{
	static int		i = 0;
	static int		bit = 8;
	static pid_t	server = 0;
	char			c;

	if (info->si_pid != 0 && server == 0)
		server = info->si_pid;
	if (signo == SIGUSR2)
		exit(ft_printf(
				"\nMessaged sent successfully to %d (Server) from %d (Client)\n",
				server, getpid()));
	if (--bit < 0)
	{
		bit = 7;
		i++;
	}
	c = g_msg[i];
	if (c != '\0' && ((c >> bit) & 1))
		kill(server, SIGUSR1);
	else
		kill(server, SIGUSR2);
	(void)content;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
		return (ft_printf("./client [server pid] [message]\n"));
	g_msg = av[2];
	sa.sa_sigaction = sig;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (kill(ft_atoi(av[1]), SIGUSR1) == -1)
		return (ft_printf("Connection failed\n"));
	while (1)
		pause();
	return (0);
}
