/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:23:28 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/16 12:26:21 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_format(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]);
	if (i <= 3)
		return (BAD);
	if (argv[1][i - 1] != 98)
		return (BAD);
	if (argv[1][i - 2] != 117)
		return (BAD);
	if (argv[1][i - 3] != 99)
		return (BAD);
	if (argv[1][i - 4] != 46)
		return (BAD);
	return (GOOD);
}

int	ft_check_textures(t_struct *data)
{
	if (ft_check_texture_file_opening(data, "NO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_opening(data, "SO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_opening(data, "WE ") == BAD)
		return (BAD);
	if (ft_check_texture_file_opening(data, "EA ") == BAD)
		return (BAD);
	return (GOOD);
}

int	ft_check_textures_missing(t_struct *data)
{
	if (ft_check_texture_file_missing(data, "NO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_missing(data, "SO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_missing(data, "WE ") == BAD)
		return (BAD);
	if (ft_check_texture_file_missing(data, "EA ") == BAD)
		return (BAD);
	return (GOOD);
}

int	ft_check_textures_duplicate(t_struct *data)
{
	if (ft_check_texture_file_duplicate(data, "NO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_duplicate(data, "SO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_duplicate(data, "WE ") == BAD)
		return (BAD);
	if (ft_check_texture_file_duplicate(data, "EA ") == BAD)
		return (BAD);
	return (GOOD);
}

int	ft_check_file(t_struct *data)
{
	if (ft_check_textures_missing(data) == BAD)
		return (printf(ERROR_FILE_MISSING), BAD);
	if (ft_check_textures(data) == BAD)
		return (printf(ERROR_FILE_OPEN), BAD);
	if (ft_check_textures_duplicate(data) == BAD)
		return (printf(ERROR_FILE_DUPLICATE), BAD);
	if (ft_check_floor(data, "F") == BAD)
		return (printf(ERROR_FILE_FLOOR), BAD);
	if (ft_check_ceiling(data, "C") == BAD)
		return (printf(ERROR_FILE_CEILING), BAD);
	return (GOOD);
}
