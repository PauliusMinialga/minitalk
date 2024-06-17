/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:51:21 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/24 12:20:13 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (*str1 && *str2 && n > 0)
	{
		if (*str1 != *str2)
		{
			return ((unsigned char) *str1 - (unsigned char) *str2);
		}
		n--;
		str1++;
		str2++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char) *str1 - (unsigned char) *str2);
}
