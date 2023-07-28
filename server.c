/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:37:13 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/28 20:53:08 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	bit;
	static char	tmp;

	if (signal == SIGUSR1)
	{
		tmp = tmp | (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		if (tmp == 0)
			write (1, "\n", 1);
		write (1, &tmp, 1);
		bit = 0;
		tmp = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
		return (ft_error());
	pid = getpid();
	write(1, "pid: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
