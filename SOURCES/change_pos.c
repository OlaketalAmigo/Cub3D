/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:58:11 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/06 13:58:12 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	change_direction(t_struct *data, int key)
{
	if (key == R_ARROW)
		data->player_x_dir = data->player_x_dir + 0.030;
	else if (key == L_ARROW)
		data->player_x_dir = data->player_x_dir - 0.030;
	if (data->player_x_dir < 0)
		data->player_x_dir = data->player_x_dir + 2 * M_PI;
	else if (data->player_x_dir > 2 * M_PI)
		data->player_x_dir = data->player_x_dir - 2 * M_PI;
	return (GOOD);
}

void	assign_next_pos(double *x, double *y, int key, double dir)
{
	double	t_x;
	double	t_y;

	t_x = cos(dir);
	t_y = sin(dir);
	if (key == W)
	{
		*x = 0.1 * t_x;
		*y = 0.1 * t_y;
	}
	else if (key == D)
	{
		*x = 0.1 * -t_y;
		*y = 0.1 * t_x;
	}
	else if (key == S)
	{
		*x = -0.1 * t_x;
		*y = -0.1 * t_y;
	}
	else if (key == A)
	{
		*x = 0.1 * t_y;
		*y = -0.1 * t_x;
	}
}

int	check_next_pos(t_struct *d, int key)
{
	double	t_x;
	double	t_y;
	int		x;
	int		y;

	assign_next_pos(&t_x, &t_y, key, d->player_x_dir);
	t_x = d->player_x + t_x;
	t_y = d->player_y + t_y;
	x = floor(t_x);
	y = floor(t_y);
	if (x < 0 || y < 0 || x >= d->height[y] || y >= d->map_h
		|| d->map[y][x] == ' ' || (d->map[y][x] == '1' && is_border(d, x, y)))
		return (BAD);
	d->player_x = t_x;
	d->player_y = t_y;
	return (GOOD);
}

int	change_position(t_struct *data, int key)
{
	if (check_next_pos(data, key) == BAD)
		return (1);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->sc_w, data->sc_h);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->len, &data->end);
	return (GOOD);
}
