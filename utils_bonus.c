/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:41:28 by riyano            #+#    #+#             */
/*   Updated: 2025/01/19 11:41:46 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	kill_wrapper(int pid, int signo)
{
	if (kill(pid, signo) < 0)
	{
		ft_putstr_fd("Kill failed\n", 1);
		exit(EXIT_FAILURE);
	}
}
