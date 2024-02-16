/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:01:13 by cgaratej          #+#    #+#             */
/*   Updated: 2024/02/16 11:36:13 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_line(char *str)
{
	char	*line;
	int		i;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_move_start(char *str)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	if (str[i] == '\n')
		i++;
	buff = malloc(1 + ft_strlen(str) - i);
	if (!buff)
		return (free(str), NULL);
	j = 0;
	while (str[i + j])
	{
		buff[j] = str[i + j];
		j++;
	}
	buff[j] = '\0';
	free(str);
	return (buff);
}

static char	*read_document(int fd, char *start_str)
{
	int		fd_read;
	char	*tmp;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (freeoffree(&start_str));
	fd_read = 1;
	while (!(ft_strchr(start_str, '\n')) && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(tmp);
			return (freeoffree(&start_str));
		}
		if (fd_read == 0 && !start_str)
			return (free(tmp), NULL);
		tmp[fd_read] = '\0';
		start_str = ft_create_start(start_str, tmp);
		if (!start_str)
			return (free(tmp), freeoffree(&start_str));
	}
	free(tmp);
	return (start_str);
}

char	*get_next_line(int fd)
{
	char		*conten;
	static char	*start_str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!start_str[fd] || !ft_strchr(start_str[fd], '\n'))
		start_str[fd] = read_document(fd, start_str[fd]);
	if (!start_str[fd])
		return (NULL);
	conten = ft_read_line(start_str[fd]);
	if (!conten)
		return (freeoffree(&start_str[fd]));
	start_str[fd] = ft_move_start(start_str[fd]);
	return (conten);
}
