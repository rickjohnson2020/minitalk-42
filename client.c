/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:26:37 by riyano            #+#    #+#             */
/*   Updated: 2025/01/16 20:06:35 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./minitalk.h"

volatile sig_atomic_t	recieved = 0;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		recieved = 1;
	else
	{
		ft_putstr_fd("Server has recieved every message.\n", 1);
		exit(0);
	}
}

static void	send_null_bits(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill_wrapper(pid, SIGUSR1);
		while (!recieved)
			usleep(100);
		recieved = 0;
		i++;
	}
}

static void	send_message(int pid, char *str)
{
	unsigned char	c;
	int		i;

	while (*str)
	{
		c = (unsigned char)*str++;
		i = 7;
		while (i >= 0)
		{
			if (((c >> i) & 1) == 1)
				kill_wrapper(pid, SIGUSR2);
			else
				kill_wrapper(pid, SIGUSR1);
			while (!recieved)
				usleep(100);
			recieved =  0;
			i--;
		}
	}
	send_null_bits(pid);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
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
	//while (1)
	//{
	//	pause();
	//}
	return (0);
}
