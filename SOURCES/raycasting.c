/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehe <hehe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:58:52 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/14 01:19:05 by hehe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	visible_height(t_struct *data, double *step, double *pos, float height)
{
	int		draw_start;
	int		draw_end;

	data->start_w = (data->sc_h - height) / 2;
	data->end_w = data->start_w + height;
	draw_start = fmax(data->start_w, 0);
	draw_end = fmin(data->end_w, data->sc_h);
	if (draw_end <= draw_start)
	{
		data->start_w = 0;
		data->end_w = 0;
		return ;
	}
	*step = data->img_h / height;
	*pos = (draw_start - data->start_w) * (*step);
	*pos = fmax(*pos, 0);
	*pos = fmin(*pos, data->img_h - 1);
	data->start_w = draw_start;
	data->end_w = draw_end;
}

void	render_vertical(t_struct *data, int x, float height, double wall_hit)
{
	double	step;
	double	pos;
	int		y;

	visible_height(data, &step, &pos, height);
	data->tex_x = (int)(wall_hit * data->img_w);
	y = 0;
	while (y < data->sc_h)
	{
		if (y < data->start_w)
			my_mlx_pixel_put(data, x, y, get_color(data, 'C'));
		else if (y < data->end_w)
		{
			apply_texture(data, x, y, pos);
			pos = pos + step;
			pos = fmin(pos, data->img_h - 1);
		}
		else
			my_mlx_pixel_put(data, x, y, get_color(data, 'F'));
		y++;
	}
}

void	draw_collumn(t_struct *data, int x, double distance, double wall_hit)
{
	float	height;

	height = data->sc_h / distance;
	if (distance <= 0)
		height = data->sc_h;
	if (height < 1)
		height = 1;
	render_vertical(data, x, height, wall_hit);
}

double	check_ray(t_struct *data, double ray_angle, double *wall_hit)
{
	t_ray	ray;

	init_struct_ray(&ray, data, ray_angle);
	while (1)
	{
		dda_step(&ray);
		if (ray.map_y >= data->map_h || ray.map_x >= data->height[ray.map_y])
			return (-1);
		if (data->map[ray.map_y][ray.map_x] == '1')
			break ;
	}
	get_wall_dir(data, &ray);
	return (final_distance(&ray, data, ray_angle, wall_hit));
}

void	init_rays(t_struct *data)
{
	double	distance;
	double	ray_angle;
	double	wall_hit;
	int		x;

	ray_angle = data->player_x_dir - (data->fov / 2);
	x = 0;
	while (ray_angle < data->player_x_dir + (data->fov / 2))
	{
		distance = check_ray(data, ray_angle, &wall_hit);
		if (distance != -1)
			draw_collumn(data, x, distance, wall_hit);
		ray_angle += data->fov / data->sc_w;
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
