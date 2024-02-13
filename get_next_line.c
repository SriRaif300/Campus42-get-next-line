/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:01:13 by cgaratej          #+#    #+#             */
/*   Updated: 2024/02/13 13:55:02 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(char *str)
{
	char	*line;
	int		i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (str && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_move_start(char *str)
{
}

char	*get_next_line(int fd)
{
	char		*tmp;
	int			fd_read;
	static char	*start_str;

	if (!fd || BUFFER_SIZE <= 0)
		return (0);
	fd_read = 1;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (0);
	while (!(ft_strchr(start_str, '\n')) && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(tmp);
			return (0);
		}
		tmp[fd_read] = '\0';
		start_str = ft_create_start(start_str, tmp);
	}
	free(tmp);
	tmp = ft_read_line(start_str);
	start_str = ft_move_start(start_str);
	return (tmp);
}
