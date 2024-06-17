/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/05 13:23:53 by pminialg      #+#    #+#                 */
/*   Updated: 2024/01/10 13:05:36 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>

//client
void	handle_client(int signal);
int		send_byte(int pid, unsigned char message);
void	handle_error(int e);
//server
void	handler(int signal, siginfo_t *info, void *ucontext);
//libft
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif