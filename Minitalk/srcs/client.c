/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:48:38 by schuah            #+#    #+#             */
/*   Updated: 2023/02/23 21:01:39 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_msg;

void	sig(int signo, siginfo_t *info, void *content)
{
	static int		i = 0;
	static int		bit = 8;
	char			c;

	// kill(info->si_pid, SIGUSR1);
	// ft_printf("hi");
	if (signo == SIGUSR2)
		exit(ft_printf("\nMessaged sent successfully to %d from %d\n", info->si_pid, getpid()));
	if (--bit < 0)
	{
		bit = 7;
		i++;
	}
	c = g_msg[i];
	if (c != '\0' && ((c >> bit) & 1))
	{
		// ft_printf("Bit: 1, Sent: 1", ((c >> bit) & 1));
		kill(info->si_pid, SIGUSR1);
	}
	else if (c != '\0')
	{
		// ft_printf("Bit: 0, Sent: 2", ((c >> bit) & 1));
		kill(info->si_pid, SIGUSR2);
	}
	else
		kill(info->si_pid, SIGUSR2);
	// ft_printf("i: %d\n", i);
	(void)content;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
		return (ft_printf("./client [server pid] [message]\n"));
	sa.sa_sigaction = sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	g_msg = av[2];
	if (kill(ft_atoi(av[1]), SIGUSR1) == -1)
		return (ft_printf("Connection failed\n"));
	while (1)
		pause();
	return (0);
}