/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:37:07 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/08/09 13:05:20 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	i = 0;
	h = (char *) haystack;
	n = (char *) needle;
	if (!*n)
		return (h);
	while (*(h + i) && i < len)
	{
		j = 0;
		while (*(n + j) && *(n + j) == *(h + i + j))
		{
			if (*(n + j + 1) == '\0' && (i + j < len))
			{
				return (h + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
