/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 09:42:17 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/23 15:00:32 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*strjoin;

	i = 0;
	j = 0;
	strjoin = malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
	if (strjoin == 0)
		return (NULL);
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strjoin[i++] = s2[j++];
	}
	strjoin[i] = '\0';
	return (strjoin);
}
