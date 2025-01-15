/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:30:02 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/15 13:56:05 by tfauve-p         ###   ########.fr       */
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
			(*count)++;
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
