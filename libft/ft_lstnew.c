/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 10:57:32 by pminialg      #+#    #+#                 */
/*   Updated: 2023/10/16 11:20:29 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*member;

	member = (t_list *)malloc(sizeof(t_list));
	if (!member)
		return (NULL);
	member -> content = content;
	member -> next = NULL;
	return (member);
}
