/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:50:40 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/18 11:50:41 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)str);
	}
	str--;
	while (i > 0 && *str)
	{
		if (*str == (unsigned char)c)
		{
			return ((char *)str);
		}
		str--;
		i--;
	}
	return (NULL);
}
