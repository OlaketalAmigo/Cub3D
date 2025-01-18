/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehe <hehe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:23:17 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/18 18:01:58 by hehe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_struct *data)
{
	int	i;
	data->north_img = mlx_xpm_file_to_image(data->mlx, data->path_to_N,
			&data->img_w, &data->img_h);
	data->south_img = mlx_xpm_file_to_image(data->mlx, data->path_to_S,
			&data->img_w, &data->img_h);
	data->east_img = mlx_xpm_file_to_image(data->mlx, data->path_to_E,
			&data->img_w, &data->img_h);
	data->west_img = mlx_xpm_file_to_image(data->mlx, data->path_to_W,
			&data->img_w, &data->img_h);
	data->height = malloc (4 * ft_nb_arg(data->map));
	if (data->height)
	{
		i = 0;
		while (data->map[i])
		{
			data->height[i] = ft_strlen(data->map[i]);
			i++;
		}
	}
}

int	deal_key(int key, t_struct *data)
{
	if (key == ESCAPE)
		ft_close(data);
	else if (key == W || key == A || key == S || key == D)
		change_position(data, key);
	else if (key == L_ARROW || key == R_ARROW)
		change_direction(data, key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	data;

	data.img_h = 48;
	data.img_w = 48;
	ft_parser(&data, argc, argv);
	if (init_data(&data) == BAD)
		ft_error_and_exit(ERROR_MALLOC_FAILED, &data);
	ft_init_mlx(&data);
	init_rays(&data);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_hook(data.win, 17, 1L << 17, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
