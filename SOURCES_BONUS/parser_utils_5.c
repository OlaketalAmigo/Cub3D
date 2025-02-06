/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:30:02 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/06 14:27:15 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_characters(t_struct *data, int i, int *count)
{
	int	j;

	j = -1;
	while (data->map[i][++j])
	{
		if (data->map[i][j] == 69 || data->map[i][j] == 78
			|| data->map[i][j] == 83 || data->map[i][j] == 87)
		{
			data->spawn_dir = (int)data->map[i][j];
			data->spawn_x = j;
			data->spawn_y = i;
			(*count)++;
		}
		else if (data->map[i][j] != 32 && data->map[i][j] != 48
			&& data->map[i][j] != 49 && data->map[i][j] != 10)
			return (BAD);
	}
	return (GOOD);
}

int	ft_check_map(t_struct *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (data->map)
	{
		while (data->map[++i])
		{
			if (ft_check_map_characters(data, i, &count) == BAD)
				return ((printf(ERROR_MAP_WRONG_CHAR)), BAD);
		}
	}
	if (count > 1)
		return (printf(ERROR_MAP_TOO_MANY_PLAYER), BAD);
	if (count == 0)
		return (printf(ERROR_MAP_MISSING_ENTRY), BAD);
	return (GOOD);
}

int	ft_check_element_order(char	**tab)
{
	int	check[7];

	int (i) = -1;
	check[0] = -1;
	check[1] = -1;
	check[2] = -1;
	check[3] = -1;
	check[4] = -1;
	check[5] = -1;
	check[6] = -1;
	while (tab[++i] && (check[0] == -1 || check[1] == -1 || check[2] == -1
			|| check[3] == -1 || check[4] == -1 || check[5] == -1
			|| check[6] == -1))
		ft_fill_order_tab(check, i, tab);
	if (check[0] < check[6] && check [1] < check[6] && check[2] < check[6]
		&& check[3] < check[6] && check[4] < check[6] && check[5] < check[6])
		return (GOOD);
	return (printf(ERROR_FILE_ELEMENT_ORDER), BAD);
}

void	ft_fill_order_tab(int *check, int i, char **tab)
{
	if (ft_strncmp(tab[i], "NO", 2) == GOOD)
		check[0] = i;
	if (ft_strncmp(tab[i], "SO", 2) == GOOD)
		check[1] = i;
	if (ft_strncmp(tab[i], "WE", 2) == GOOD)
		check[2] = i;
	if (ft_strncmp(tab[i], "EA", 2) == GOOD)
		check[3] = i;
	if (ft_strncmp(tab[i], "F", 1) == GOOD)
		check[4] = i;
	if (ft_strncmp(tab[i], "C", 1) == GOOD)
		check[5] = i;
	if (ft_check_upper_wall(tab[i]) == GOOD)
		check[6] = i;
}

void	ft_replace_characters(char **tab, char s, char c)
{
	int	i;
	int	j;

	i = -1;
	if (tab)
	{
		while (tab[++i])
		{
			j = -1;
			while (tab[i][++j])
			{
				if (tab[i][j] == s)
					tab[i][j] = c;
			}
		}
	}
}
