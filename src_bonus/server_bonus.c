/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 09:23:47 by pminialg      #+#    #+#                 */
/*   Updated: 2024/01/11 11:47:06 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signal, siginfo_t *info, void *ucontext)
{
	static int				bit_index = 0;
	static unsigned char	c;

	(void)ucontext;
	c |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (c == '\0')
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			ft_putchar_fd((char)c, 1);
		bit_index = 0;
		c = 0;
	}
	else
		c <<= 1;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("\e[1;35mpid:   ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n\e[0m", 1);
	while (1)
		pause();
	return (0);
}
