/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:33:58 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/06/15 20:44:20 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_null(char *buf)
{
	free(buf);
	buf = NULL;
	return (NULL);
}

int	ft_strlenc(const char *s, int c)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s && s[len] != '\0' && s[len] != (unsigned char)c)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s && s[i] && s[i] != (char)c)
		i++;
	if (s && s[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_strjoin_and_free(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1)
	{
		s1 = malloc (1);
		if (!s1)
			return (NULL);
		*s1 = 0;
	}
	new = (char *) malloc ((ft_strlenc(s1, 0) + ft_strlenc(s2, 0) + 1));
	if (!new && !free_null(s1))
		return (NULL);
	i = -1;
	while (s1[++i])
	new[i] = s1[i];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = 0;
	s1 = free_null(s1);
	return (new);
}
