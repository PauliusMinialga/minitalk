/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 10:28:08 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/20 09:50:17 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*new_ptr1;
	unsigned char	*new_ptr2;
	size_t			i;

	new_ptr1 = (unsigned char *) ptr1;
	new_ptr2 = (unsigned char *) ptr2;
	i = 0;
	while (new_ptr1 && new_ptr2 && i < num)
	{
		if (*new_ptr1 != *new_ptr2)
		{
			return (*new_ptr1 - *new_ptr2);
		}
		i++;
		new_ptr1++;
		new_ptr2++;
	}
	if (i < num)
	{
		return (*new_ptr1 - *new_ptr2);
	}
	return (0);
}
