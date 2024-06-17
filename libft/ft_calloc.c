/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 09:16:21 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/18 11:47:17 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*result;
	size_t	total_size;

	total_size = num_elements * element_size;
	if (element_size != 0 && num_elements != 0
		&& total_size / num_elements != element_size)
		return (NULL);
	result = malloc(num_elements * element_size);
	if (result != NULL)
		ft_memset(result, 0, num_elements * element_size);
	return (result);
}
