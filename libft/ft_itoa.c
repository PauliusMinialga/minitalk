/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 13:55:02 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/24 12:14:00 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static char	*ft_reverse(char *s, int counter)
{
	int		i;
	char	temp;
	int		j;

	i = 0;
	j = counter - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}

static char	*ft_malloc(unsigned int num, int sign)
{
	int		counter;
	char	*s;

	counter = 0;
	while (num != 0)
	{
		num /= 10;
		counter++;
	}
	if (sign < 0)
		counter++;
	s = malloc(sizeof(char) * (counter + 1));
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_itoa(int n)
{
	char			*string;
	int				i;
	int				sign;
	unsigned int	num;

	i = 1;
	sign = ft_sign(n);
	num = n * sign;
	if (num == 0)
		return (ft_strdup("0"));
	string = ft_malloc(num, sign);
	if (string == NULL)
		return (NULL);
	string[0] = '\0';
	while (num != 0)
	{
		string[i++] = (num % 10) + 48;
		num /= 10;
	}
	if (sign < 0)
		string[i++] = '-';
	string = ft_reverse(string, i);
	return (string);
}
