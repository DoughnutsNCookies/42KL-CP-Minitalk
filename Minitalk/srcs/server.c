/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:17:37 by schuah            #+#    #+#             */
/*   Updated: 2023/02/23 21:04:17 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig(int signo, siginfo_t *info, void *content)
{
	static pid_t	client = 0;
	static int		bit = 0;
	static char		c = '\0';

	if (client == 0 && signo == SIGUSR1)
	{
		client = info->si_pid;
		kill(client, SIGUSR1);
	}
	else
	{
		c = (c << 1) | (signo == SIGUSR1);
		// ft_printf("Received: %d\n", signo == SIGUSR1);
		if (++bit == 8)
		{
			bit = 0;
			if (c == '\0')
			{
				// ft_printf("Sent!\n");
				kill(client, SIGUSR2);
				client = 0;
				bit = 0;
				return ;
			}
			// kill(client)
			write(1, &c, 1);
			c = '\0';
		}
		// else
			// c <<= 1;
		// if (signo == SIGUSR1)
		// {
		// 	ft_printf("1");
		// 	c = (c << 1) | 1;
		// }
		// if (signo == SIGUSR2)
		// {
		// 	ft_printf("0");
		// 	c = (c << 1) | 0;
		// }
	}
	kill(client, SIGUSR1);
	// if (++bit > 8)
	// {
	// 	bit = 0;
	// 	ft_printf("%c\n", c);
	// 	c = '\0';
	// }
	(void)info;
	(void)content;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
