/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:06:31 by cgaratej          #+#    #+#             */
/*   Updated: 2024/02/13 13:09:09 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ch;

	if (!s)
		return (0);
	i = 0;
	ch = (char *)s;
	while (ch[i] != '\0')
	{
		if (ch[i] == (char)c)
			return (&ch[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&ch[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (0);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (0);
}

char	*ft_create_start(char *start, char *buffer)
{
	char	*str;

	if (!start)
	{
		start = malloc(1 * sizeof(char));
		if (!start)
			return (0);
		start[0] = '\n';
	}
	if (!start || !buffer)
		return (0);
	str = ft_strjoin(start, buffer);
	free(start);
	return (str);
}
