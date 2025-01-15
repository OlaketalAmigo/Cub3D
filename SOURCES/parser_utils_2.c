/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:23:20 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/15 11:23:21 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_texture_file_opening(t_struct *data, char *s)
{
	int		i;
	int		j;
	char	*to_open;
	char	*trimmed;

	i = 0;
	while (data->file[i])
	{
		trimmed = ft_strtrim(data->file[i], " ");
		trimmed = ft_remove_space(trimmed);
		if (ft_strncmp(trimmed, s, 2) == GOOD)
		{
			to_open = ft_get_path(trimmed);
			j = open(to_open, O_RDONLY);
			if (j == -1)
				return (free(to_open), BAD);
			close(j);
			return (free(to_open), GOOD);
		}
		free(trimmed);
		i++;
	}
	return (BAD);
}

int	ft_check_texture_file_missing(t_struct *data, char *s)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (data->file[i])
	{
		trimmed = ft_strtrim(data->file[i], " ");
		if (ft_strncmp(trimmed, s, 3) == GOOD)
			return (free(trimmed), GOOD);
		free(trimmed);
		i++;
	}
	return (BAD);
}

int	ft_check_texture_file_duplicate(t_struct *data, char *s)
{
	char	*trimmed;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (data->file[i])
	{
		trimmed = ft_strtrim(data->file[i], " ");
		if (ft_strncmp(trimmed, s, 3) == GOOD)
			count++;
		free(trimmed);
		i++;
	}
	if (count == 1)
		return (GOOD);
	return (BAD);
}
