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
void	send_signal(int pid, char *str)
{
	printf("send_signal function is executed.\n");
	int result = kill(pid, SIGUSR1);
	if (result == 0)
		printf("Success!\n");
	else
		printf("Fail.\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	send_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
	{
		pause();
	}
	return (0);
}
