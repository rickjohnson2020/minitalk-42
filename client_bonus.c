/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:38:47 by riyano            #+#    #+#             */
/*   Updated: 2025/01/19 11:40:08 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./minitalk_bonus.h"

volatile sig_atomic_t	g_recieved = 0;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_recieved = 1;
	else
	{
		ft_putstr_fd("Server has recieved every message.\n", 1);
		exit(0);
	}
}

void	send_message(int pid, char *str)
{
	unsigned char	c;
	int				i;

	while (1)
	{
		c = (unsigned char)*str++;
		i = 7;
		while (i >= 0)
		{
			if (((c >> i) & 1) == 1)
				kill_wrapper(pid, SIGUSR2);
			else
				kill_wrapper(pid, SIGUSR1);
			while (!g_recieved)
				usleep(100);
			g_recieved = 0;
			i--;
		}
		if (c == '\0')
			break ;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client_bonus <PID> <message>\n", 1);
		return (0);
	}
	if (signal(SIGUSR1, handler) < 0)
	{
		ft_putstr_fd("SIGUSR1 signal failed\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal(SIGUSR2, handler) < 0)
	{
		ft_putstr_fd("SIGUSR2 signal failed\n", 1);
		exit(EXIT_FAILURE);
	}
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
