/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:37:43 by pminialg      #+#    #+#                 */
/*   Updated: 2023/11/15 11:43:15 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*new_dest;
	const unsigned char		*new_src;

	new_dest = (unsigned char *)dest;
	new_src = (const unsigned char *)src;
	if (new_dest == NULL && new_src == NULL)
		return (NULL);
	if (new_dest > new_src)
	{
		while (n > 0)
		{
			new_dest[n - 1] = new_src[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(new_dest, new_src, n);
	}
	return (new_dest);
}
