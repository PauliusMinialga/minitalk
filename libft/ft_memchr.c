/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:06:18 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/18 11:48:44 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*ptr_pos;
	size_t				i;

	ptr_pos = (const unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		if (ptr_pos[i] == (unsigned char)value)
		{
			return ((void *)(ptr_pos + i));
		}
		i++;
	}
	return (NULL);
}
