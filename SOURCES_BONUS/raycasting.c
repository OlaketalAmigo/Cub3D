/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:59:50 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/06 13:59:51 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_struct *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	render_vertical(t_struct *data, int x, float height, double wall_hit)
{
	double	start;
	double	end;
	double	step;

	start = (data->sc_h - height) / 2;
	end = start + height;
	step = (double)data->img_h / height;
	double (pos) = 0;
	data->tex_x = (int)(wall_hit * data->img_w);
	int (y) = 0;
	while (y < data->sc_h)
	{
		if (y < start)
			my_mlx_pixel_put(data, x, y, get_color(data, 'C'));
		else if (y >= start && y < end)
		{
			apply_texture(data, x, y, pos);
			pos = pos + step;
			if (pos >= data->img_h)
				pos = data->img_h - 1;
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
	render_minimap(data);
}
