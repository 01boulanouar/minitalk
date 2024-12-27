/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:57:36 by moboulan          #+#    #+#             */
/*   Updated: 2024/12/27 05:00:25 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	byte;
	static int	i;
	static int	previous_pid;

	(void) context;
	if (previous_pid != info->si_pid)
	{
		previous_pid = info->si_pid;
		i = 0;
		byte = 0;
	}
	if (signum == SIGUSR1)
		byte = byte | (1 << i);
	i++;
	if (i > 7)
	{
		ft_printf("%c", byte);
		i = 0;
		byte = 0;
	}
}

void	init_action(void)
{
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
}

int	main(int argc, char **argv)
{
	int					pid;

	(void) argv;
	if (argc != 1)
		exit(1);
	pid = getpid();
	ft_printf("%d\n", pid);
	init_action();
	while (1)
		;
}
