/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:31:29 by riyano            #+#    #+#             */
/*   Updated: 2025/01/13 18:53:24 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	handler(int num)
{
	if (num == SIGUSR1)
	{
		printf("Sample message.\n");
	}
	exit(0);
}

int	main(void)
{
	signal(SIGUSR1, handler);
	while (1)
	{
		printf("%d\n", getpid());
		pause();
	}
	return (0);
}
