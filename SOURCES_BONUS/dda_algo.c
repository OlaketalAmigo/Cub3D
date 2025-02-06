/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:59:19 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/06 13:59:20 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_ray(t_ray *ray, t_struct *data, double ray_angle)
{
	ray->dir_x = cos(ray_angle);
	ray->dir_y = sin(ray_angle);
	ray->map_x = (int)data->player_x;
	ray->map_y = (int)data->player_y;
	ray->delta_x = fabs(1 / ray->dir_x + 0.0000001);
	ray->delta_y = fabs(1 / ray->dir_y + 0.0000001);
	ray->step_x = 1;
	if (ray->dir_x > 0)
		ray->side_x = (ray->map_x + 1.0 - data->player_x) * ray->delta_x;
	else
	{
		ray->step_x = -1;
		ray->side_x = (data->player_x - ray->map_x) * ray->delta_x;
	}
	ray->step_y = 1;
	if (ray->dir_y > 0)
		ray->side_y = (ray->map_y + 1.0 - data->player_y) * ray->delta_y;
	else
	{
		ray->step_y = -1;
		ray->side_y = (data->player_y - ray->map_y) * ray->delta_y;
	}
}

void	dda_step(t_ray *ray)
{
	if (ray->side_x < ray->side_y)
	{
		ray->side_x += ray->delta_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_y += ray->delta_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

double	final_distance(t_ray *ray, t_struct *d, double ray_a, double *wall_h)
{
	int	wall;

	wall = ray->side;
	if (ray->side == 0)
	{
		ray->distance = (ray->map_x - d->player_x
				+(1 - ray->step_x) / 2) / ray->dir_x;
		ray->wall_x = d->player_y + ray->dir_y * ray->distance;
	}
	else
	{
		ray->distance = (ray->map_y - d->player_y
				+ (1 - ray->step_y) / 2) / ray->dir_y;
		ray->wall_x = d->player_x + ray->dir_x * ray->distance;
	}
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
	if ((wall == 0 && ray->step_x == -1) || (wall == 1 && ray->step_y == -1))
		ray->wall_x = 1 - ray->wall_x;
	*wall_h = ray->wall_x;
	return (ray->distance * cos(ray_a - d->player_x_dir));
}
