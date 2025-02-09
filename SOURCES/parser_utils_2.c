/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:58:33 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/09 14:05:24 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_save_path(t_struct *data, char *s, char *to_open)
{
	if (ft_strncmp("NO", s, 2) == GOOD)
		data->path_to_n = ft_strdup(to_open);
	if (ft_strncmp("SO", s, 2) == GOOD)
		data->path_to_s = ft_strdup(to_open);
	if (ft_strncmp("WE", s, 2) == GOOD)
		data->path_to_w = ft_strdup(to_open);
	if (ft_strncmp("EA", s, 2) == GOOD)
		data->path_to_e = ft_strdup(to_open);
}

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
			ft_save_path(data, s, to_open);
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

int	ft_remove_ending_newlines(t_struct *data)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = ft_nb_arg(data->file) - 1;
	while (data->file[i] && ft_strlen(data->file[i]) == 0)
		i--;
	tmp = malloc ((i + 2) * 8);
	if (!tmp)
		return (BAD);
	j = -1;
	while (++j <= i)
	{
		k = -1;
		tmp[j] = malloc ((ft_strlen(data->file[j]) + 1) * 1);
		while (++k < ft_strlen(data->file[j]))
			tmp[j][k] = data->file[j][k];
		tmp[j][k] = '\0';
	}
	tmp[j] = NULL;
	ft_free(data->file);
	data->file = tmp;
	return (GOOD);
}
