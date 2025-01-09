/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:12:08 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/06/01 16:15:26 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && lst->content)
		del(lst->content);
	free(lst);
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
        ft_lstadd_back(&head, ft_lstnew(ft_strdup("Ultimo")));
        ft_lstadd_back(&head, ft_lstnew(ft_strdup("Borrable")));
        ft_lstadd_back(&head, ft_lstnew(ft_strdup("Otro")));
        tmp = head;
        while (tmp)
        {
                if (tmp && tmp->content)
					printf ("%s\n", (char *)tmp->content);
                tmp = tmp->next;
        }
        printf ("SIZE=%d\n", ft_lstsize(head));
        printf ("LAST=%s\n", (char *)(ft_lstlast(head))->content);
        return (0);
}
*/
