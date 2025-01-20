/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehe <hehe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:23:17 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/20 06:24:29 by hehe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_struct *data)
{
	int	i;

	data->north_img = mlx_xpm_file_to_image(data->mlx, data->path_to_n,
			&data->img_w, &data->img_h);
	data->south_img = mlx_xpm_file_to_image(data->mlx, data->path_to_s,
			&data->img_w, &data->img_h);
	data->east_img = mlx_xpm_file_to_image(data->mlx, data->path_to_e,
			&data->img_w, &data->img_h);
	data->west_img = mlx_xpm_file_to_image(data->mlx, data->path_to_w,
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

int	key_release(int key, t_struct *data)
{
	if (key == W)
		data->w = NO;
	else if (key == A)
		data->a = NO;
	else if (key == S)
		data->s = NO;
	else if (key == D)
		data->d = NO;
	else if (key == L_ARROW)
		data->l_arrow = NO;
	else if (key == R_ARROW)
		data->r_arrow = NO;
	return (0);
}

int	key_press(int key, t_struct *data)
{
	if (key == ESCAPE)
		ft_close(data);
	if (key == W)
		data->w = YES;
	else if (key == A)
		data->a = YES;
	else if (key == S)
		data->s = YES;
	else if (key == D)
		data->d = YES;
	else if (key == L_ARROW)
		data->l_arrow = YES;
	else if (key == R_ARROW)
		data->r_arrow = YES;
	return (0);
}

int	game_loop(t_struct *data)
{
	if (data->w == YES)
		change_position(data, W);
	if (data->a == YES)
		change_position(data, A);
	if (data->s == YES)
		change_position(data, S);
	if (data->d == YES)
		change_position(data, D);
	if (data->l_arrow == YES)
		change_direction(data, L_ARROW);
	if (data->r_arrow == YES)
		change_direction(data, R_ARROW);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->sc_w, data->sc_h);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->len, &data->end);
	init_rays(data);
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
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.win, 17, 1L << 17, ft_close, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
