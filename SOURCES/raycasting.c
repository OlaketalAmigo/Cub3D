#include "cub3d.h"

void	my_mlx_pixel_put(t_struct *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	render_vertical(t_struct *data, int x, int height)
{
	int	y;
	int	start;
	int	end;

	start = (data->sc_h - height) / 2;
	end = start + height;
	y = 0;
	while (y < data->sc_h)
	{
		if (y < start)
			my_mlx_pixel_put(data, x, y, 14753280);
		else if (y >= start && y < end)
			my_mlx_pixel_put(data, x, y, 0x00FF00);
		else
			my_mlx_pixel_put(data, x, y, 14443520);
		y++;
	}
}

void	draw_collumn(t_struct *data, int x, double distance)
{
	int	height;

	height = data->sc_h / distance;
	render_vertical(data, x, height);
}

double	check_ray(t_struct *data, double ray_angle)
{
	double	distance;
	int		x;
	int		y;

	distance = 0.0;
	x = data->player_x + cos(ray_angle) * distance;
	y = data->player_y + sin(ray_angle) * distance;
	while (distance < data->ray_len && x < data->map_w && y < data->map_h
		&& x >= 0 && y >= 0)
	{
		x = data->player_x + cos(ray_angle) * distance;
		y = data->player_y + sin(ray_angle) * distance;
		if (data->map[y][x] == '1')
			return (distance);
		distance = distance + 0.1;
	}
	return (-1);
}

void	init_rays(t_struct *data)
{
	double	distance;
	double	angle;
	double	step;
	int		x;

	step = data->fov / (double)data->sc_w;
	angle = data->player_x_dir - (data->fov / 2);
	x = 0;
	while (x < data->sc_w)
	{
		distance = check_ray(data, angle);
		if (distance != -1)
			draw_collumn(data, x, distance);
		angle = angle + step;
		x++;
	}
}
