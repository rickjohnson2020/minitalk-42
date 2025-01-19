/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:40:21 by riyano            #+#    #+#             */
/*   Updated: 2025/01/19 11:41:15 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./minitalk_bonus.h"

static void	check_and_reset(pid_t pid, unsigned char *c, int *count)
{
	static pid_t	current_pid = 0;

	if (current_pid == 0)
		current_pid = pid;
	else if (current_pid != pid)
	{
		current_pid = pid;
		*c = 0;
		*count = 0;
	}
}

static void	send_recieved_signal(pid_t pid, unsigned char *c, int *count)
{
	ft_putchar_fd('\n', 1);
	kill_wrapper(pid, SIGUSR2);
	*c = 0;
	*count = 0;
}

void	handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit_count;
	pid_t					client_pid;

	(void)context;
	client_pid = info->si_pid;
	check_and_reset(client_pid, &c, *bit_count);
	c <<= 1;
	if (signo == SIGUSR2)
		c |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
		{
			send_recieved_signal(client_pid, &c, &bit_count);
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		bit_count = 0;
	}
	kill_wrapper(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_bzero(&sa, 0);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
	{
		ft_putstr_fd("sigacton SIGUSR1 failed\n", 1);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
	{
		ft_putstr_fd("sigaction SIGUSR2 failed\n", 1);
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
