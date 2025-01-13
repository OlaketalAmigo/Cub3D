#include "cub3d.h"

void	my_mlx_pixel_put(t_struct *d, int x, int y, int color)
{
	char	*dst;

	dst = d->graph.addr + (y * d->graph.line_length + x * (d->graph.bpp / 8));
	*(unsigned int *)dst = color;
}

void	render_vertical(t_struct *data, int x, int height)
{
	int	y;
	int	start;
	int	end;

	start = (data->screen_h - height) / 2;
	end = start + height;
	y = 0;
	while (y < data->screen_h)
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

	height = data->screen_h / distance;
	render_vertical(data, x, height);
}

double	check_ray(t_struct *data, t_p *p, double ray_angle)
{
	double	distance;
	int		x;
	int		y;

	distance = 0.0;
	while (distance < data->ray_len) // doit peut etre ajouter de pas depasser les limites de la map
	{
		x = p->x_pos + cos(ray_angle) * distance;
		y = p->y_pos + sin(ray_angle) * distance;
		if (data->map[y][x] == '1')
			return (distance);
		distance = distance + 0.1;
	}
	return (-1);
}

void	init_rays(t_struct *data, t_p *p)
{
	double	distance;
	double	angle;
	double	step;
	int		x;

	step = data->fov / (double)data->screen_w;
	angle = p->x_dir - (data->fov / 2);
	x = 0;
	while (x < data->screen_w)
	{
		distance = check_ray(data, p, angle);
		if (distance != -1)
			draw(data, x, distance);
		angle = angle + step;
		x++;
	}
}
