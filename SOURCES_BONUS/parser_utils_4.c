/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:59:39 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/06 13:59:40 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_whitespace_line(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		if (ft_check_upper_wall(tab[i]) == GOOD)
			break ;
		j = 0;
		while (tab[i][j] && tab[i][j] == 32)
			j++;
		if (j == ft_strlen(tab[i]) && j != 0)
			return (printf(ERROR_FILE_SPACES), BAD);
	}
	return (GOOD);
}

int	ft_check_upper_wall(char *string)
{
	int	i;

	i = -1;
	if (!string || ft_strlen(string) == 0)
		return (BAD);
	while (string[++i])
	{
		if (string[i] != 49 && string[i] != 32 && string[i] != 48)
			return (BAD);
	}
	return (GOOD);
}

int	ft_check_one_block(t_struct *data)
{
	int	i;

	i = -1;
	if (data->map)
	{
		while (data->map[++i])
		{
			if (ft_strlen(data->map[i]) == 1 && data->map[i][0] == '\n')
				return (printf(ERROR_MAP_ONE_BLOCK), BAD);
		}
	}
	return (GOOD);
}

int	ft_check_border(t_struct *data, int i)
{
	int	j;

	j = -1;
	ft_replace_characters(data->map, 32, 49);
	while (data->map[i][++j])
	{
		if (data->map[i][j] == 48)
		{
			if (j == 0 || i == 0 || data->map[i + 1] == NULL
				|| data->map[i][j + 1] == 10 || data->map[i + 1][j] == '\0'
				|| data->map[i - 1][j] == '\0')
				return (BAD);
		}
		if (data->map[i][j] == 69 || data->map[i][j] == 78
			|| data->map[i][j] == 83 || data->map[i][j] == 87)
		{
			if (j == 0 || i == 0 || !data->map[i + 1]
				|| data->map[i][j + 1] == 10)
				return (BAD);
		}
	}
	return (GOOD);
}

int	ft_check_cornered_by_walls(t_struct *data)
{
	int	i;

	if (data->map)
	{
		i = -1;
		while (data->map[++i])
		{
			if (ft_check_border(data, i) == BAD)
				return (printf(ERROR_MAP_BORDER), BAD);
		}
		return (GOOD);
	}
	return (printf(ERROR_MALLOC_FAILED), BAD);
}
