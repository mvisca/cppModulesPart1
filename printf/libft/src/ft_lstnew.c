/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:12:08 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/06/01 16:15:29 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (void *) malloc (sizeof(t_list));
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}

/*
int	main(void)
{
	char	s1[] = "Hola";
	char	s2[] = "Mundo";
	t_list	*head;
	t_list	*tmp;

	
	head = ft_lstnew(s1);
	head->next = ft_lstnew(s2);
	tmp = head;
	while (tmp)
	{
		printf ("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
*/
