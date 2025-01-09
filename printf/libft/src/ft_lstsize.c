/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:12:08 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/06/01 16:15:29 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ncount;

	ncount = 0;
	while (lst)
	{
		lst = lst->next;
		ncount++;
	}
	return (ncount);
}

/*
int     main(void)
{
        char    s1[] = "Hola";
        char    s2[] = "Mundo";
        t_list  *head;
        t_list  *tmp;

        head = ft_lstnew(s1);
        head->next = ft_lstnew(s2);
                ft_lstadd_front(&head, ft_lstnew(ft_strdup("Primero")));
                tmp = head;
        while (tmp)
        {
                printf ("%s\n", (char *)tmp->content);
                tmp = tmp->next;
        }
		printf ("SIZE=%d\n", ft_lstsize(head));
        return (0);
}
*/
