/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:26:37 by riyano            #+#    #+#             */
/*   Updated: 2025/01/13 17:51:39 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

//TOOD: convert String to binary and pass them to kill function using SIGUSR1/2
//int	convert_to_binary(char c)
//{
//	int	binary;
//
//	(c >> i) & 1
//}

void	handler(int num)
{
	int bit;

	if (num == SIGUSR1)
		bit = 0;
		
}

void	send_signal(int pid, char *str)
{
	printf("send_signal function is executed.\n");
	char	c;
	int		i;
	int		result;

	while (*str)
	{
		c = *str++;
		i = 7;
		while (i >= 0)
		{
			if (((c >> i) & 1) == 1) // means 1
			{
				result = kill(pid, SIGUSR2);
				printf("Sent SIGUSR2\n");
			}
			else // means 0
			{
				result = kill(pid, SIGUSR1);
				printf("Sent SIGUSR1\n");
			}
			if (result != 0)
			{
				printf("Failed to send signal.\n");
				exit(0);
			}
			usleep(100000);
			i--;
		}
	}
	printf("Message sent.\n");
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	//signal(SIGUSR1, handler);
	//signal(SIGUSR2, handler);
	send_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
	{
		pause();
	}
	return (0);
}
