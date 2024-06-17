/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 11:20:09 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/23 15:02:54 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*str1;

	start = (char *)s1;
	while (*start && is_in_set(*start, set))
		start++;
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (end > start && is_in_set(*end, set))
		end--;
	str1 = malloc((end - start + 2) * sizeof(char));
	if (!str1)
		return (NULL);
	str1 = ft_memmove(str1, start, (end - start + 1));
	str1[end - start + 1] = '\0';
	return (str1);
}
