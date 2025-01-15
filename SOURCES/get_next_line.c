/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:23:13 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/15 11:23:14 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_read_line(int fd, char **stock)
{
	int			i;
	char		*line;

	line = malloc ((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!line)
		return (0);
	i = read(fd, line, BUFFER_SIZE);
	if (i == -1 || i == 0)
	{
		free(line);
		return (i);
	}
	line[i] = '\0';
	*stock = ft_strjoin(*stock, line);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	x = 1;
	while (ft_strchr(stock, '\n') == 0)
	{
		x = ft_read_line(fd, &stock);
		if (x == 0)
			break ;
		if (x == -1)
			return (NULL);
	}
	line = ft_to_return(stock);
	stock = ft_to_keep(stock);
	return (line);
}
