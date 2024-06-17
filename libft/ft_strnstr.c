/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 11:05:27 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/18 11:50:36 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (*haystack != '\0' && i < len)
	{
		j = 0;
		while (*haystack == *needle && i + j < len)
		{
			haystack++;
			needle++;
			j++;
			if (*needle == '\0')
				return ((char *)haystack - j);
		}
		needle -= j;
		haystack -= j;
		haystack++;
		i++;
	}
	return (NULL);
}
