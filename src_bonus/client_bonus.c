/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 09:23:43 by pminialg      #+#    #+#                 */
/*   Updated: 2024/01/11 15:33:50 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

bool	g_can_send = true;

void	handle_client(int signal)
{
	if (signal == SIGUSR1)
		g_can_send = true;
	if (signal == SIGUSR2)
		ft_putstr_fd("\e[1;32mThe whole message was received!\n", 1);
}

int	send_byte(int pid, unsigned char message)
{
	int				i;
	unsigned char	c;

	c = message;
	i = 7;
	while (i >= 0 && g_can_send == true)
	{
		g_can_send = false;
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				handle_error(404);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				handle_error(404);
		}
		i--;
		while (g_can_send == false)
			usleep(3);
	}
	return (0);
}

void	handle_error(int e)
{
	if (e == 400)
	{
		ft_putstr_fd("\e[1;31mERROR!\n", 1);
		ft_putstr_fd("\e[1;32mThe correct format is:\n", 1);
		ft_putstr_fd("\e[1;32m./client <pid> <message_to_send>\n", 1);
	}
	if (e == 404)
	{
		ft_putstr_fd("\e[1;31mWrong <pid>!\n", 1);
		ft_putstr_fd("\e[1;31mCheck the server <pid>\n", 1);
	}
	exit (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	signal(SIGUSR1, handle_client);
	signal(SIGUSR2, handle_client);
	if (argc != 3)
		handle_error(400);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		handle_error(404);
	while (argv[2][i])
	{
		send_byte(pid, argv[2][i]);
		i++;
	}
	send_byte(pid, '\0');
	return (0);
}
