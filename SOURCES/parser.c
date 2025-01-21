/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehe <hehe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:23:30 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/18 18:02:25 by hehe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_line(char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = open(argv[1], O_RDONLY);
	if (i == -1)
		ft_print_error_and_exit(ERROR_MAP_FILE_OPEN);
	j = 0;
	tmp = get_next_line(i);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(i);
		j++;
	}
	close (i);
	return (j);
}

int	ft_set_up_map(t_struct *data)
{
	int	end;
	int	start;
	int	i;

	end = -1;
	start = -1;
	i = -1;
	while (data->file[++end] && start == -1)
	{
		if (ft_check_upper_wall(data->file[end]) == GOOD)
			start = end;
	}
	if (start == -1 || start == 0)
		return (BAD);
	while (data->file[end])
		end++;
	data->map = malloc (8 * (end - start + 1));
	if (!data->map)
		return (BAD);
	while (++i + start < end)
		data->map[i] = ft_fill_map(data->file[start + i]);
	data->map[i] = NULL;
	return (GOOD);
}

void	ft_set_up_cub3d_file(t_struct *data, char **argv)
{
	char	*string;
	int		nb_line;
	int		fd;
	int		i;

	nb_line = ft_count_line(argv);
	data->file = malloc(8 * (nb_line + 1));
	if (data->file)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (free(data->file), ft_print_error_and_exit(ERROR_OPEN));
		string = get_next_line(fd);
		i = -1;
		while (++i != -1 && string)
		{
			data->file[i] = string;
			string = get_next_line(fd);
		}
		data->file[i] = NULL;
		close(fd);
	}
	else
		ft_print_error_and_exit(ERROR_MALLOC_FAILED);
}

void	ft_set_up_final_map(t_struct *data)
{
	int		i;
	int		j;
	char	**tmp;

	i = ft_nb_arg(data->map);
	data->map_w = 0;
	if (i != 0)
	{
		tmp = malloc (8 * (i + 1));
		j = 0;
		while (data->map[j])
		{
			tmp[j] = ft_strtrim(data->map[j], "\n");
			if (ft_strlen(tmp[j]) > data->map_w)
				data->map_w = ft_strlen(tmp[j]);
			j++;
		}
		tmp[j] = NULL;
		ft_free(data->map);
		data->map = tmp;
		data->map_h = i;
	}
}

int	ft_parser(t_struct *data, int argc, char **argv)
{
	if (argc != 2)
		ft_print_error_and_exit(ERROR_ARGS_NUMBER);
	if (ft_check_map_format(argv) == BAD)
		ft_print_error_and_exit(ERROR_MAP_FORMAT);
	ft_set_up_cub3d_file(data, argv);
	if (ft_check_element_order(data->file) == BAD)
		return (ft_free(data->file), exit(EXIT_FAILURE), 1);
	if (ft_check_whitespace_line(data->file) == BAD)
		return (ft_free(data->file), exit(EXIT_FAILURE), 1);
	if (ft_check_file(data) == BAD)
		return (ft_free(data->file), exit(EXIT_FAILURE), 1);
	if (ft_set_up_map(data) == BAD)
		return (ft_free(data->file), exit(EXIT_FAILURE), 1);
	if (ft_check_map(data) == BAD)
		return (ft_free(data->file), ft_free(data->map), exit(EXIT_FAILURE), 1);
	if (ft_check_one_block(data) == BAD)
		return (ft_free(data->file), ft_free(data->map), exit(EXIT_FAILURE), 1);
	if (ft_check_cornered_by_walls(data) == BAD)
		return (ft_free(data->file), ft_free(data->map), exit(EXIT_FAILURE), 1);
	ft_set_up_final_map(data);
	return (0);
}
