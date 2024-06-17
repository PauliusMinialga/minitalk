/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 11:45:46 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/20 13:51:08 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	size_t	counter;
	int		i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static void	free_tab(char **tab, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*strndup_mod(const char *s, size_t n)
{
	char		*str;
	size_t		i;
	static int	counter;

	i = 0;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	counter++;
	i = 0;
	while (s[i] && i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	*assign_tab_value(char **tab, char const *s, char c, int i)
{
	int		start;
	int		end;
	int		k;

	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		tab[k] = strndup_mod(&s[start], end - start);
		if (tab[k] == NULL)
		{
			free_tab(tab, k);
			return (NULL);
		}
		k++;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	assign_tab_value(tab, s, c, i);
	return (tab);
}
