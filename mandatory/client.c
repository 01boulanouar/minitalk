/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:57:33 by moboulan          #+#    #+#             */
/*   Updated: 2024/12/26 20:35:40 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}

void	send_character(int pid, char c)
{
	int		i;
	int		bit;

	i = 0;
	while (i < 8)
	{
		bit = 1 & (c >> i);
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Failed to send SIGUSR1");
		}
		else if (bit == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Failed to send SIGUSR2");
		}
		usleep(150);
		i++;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_character(pid, str[i]);
		i++;
	}
	send_character(pid, '\0');
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (argc != 3)
		ft_error("Must give 2 arguments: ./client pid message");
	if (!ft_isint(argv[1]))
		ft_error("Server PID must be an integer");
	server_pid = ft_atol(argv[1]);
	if (server_pid < 0)
		ft_error("Server PID must be positive");
	message = argv[2];
	if (message[0] == '\0')
		ft_error("Message cannot be an empty string");
	if (kill(server_pid, 0) == -1)
		ft_error("No Server is running with this PID");
	send_message(server_pid, message);
}
