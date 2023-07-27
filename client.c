/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:36:35 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/27 20:00:05 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, char ch)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((ch & 1 << bit) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

void	send_message(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_bit(pid, str[i]);
		usleep(1000);
		i++;
	}
	send_bit(pid, '\n');
	send_bit(pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		return (ft_error());
	else
	{
		pid = ft_atoi(av[1]);
		if (pid < 100 || pid > 99999)
		{
			ft_putstr_fd("PID ERROR\n", 1);
			return (0);
		}
		send_message(pid, av[2]);
	}
	return (0);
}
