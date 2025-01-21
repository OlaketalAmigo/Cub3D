#include "cub3d.h"

void	my_mlx_pixel_put(t_struct *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	apply_texture(t_struct *d, int x, int y, double pos) // PAS FINI
{
	char				*tex;
	unsigned int		color;

	d->tex_y = (int)pos & (d->img_h - 1); // BINAIRE QUI NOUS DONNE SUR QUELLE RANGEE LA TEXTURE SE TROUVE
	if (d->tex_x < 0)
		d->tex_x = 0;
	else if (d->tex_x >= d->img_w)
		d->tex_x = d->img_w - 1;
	if (d->wall_dir == 'N')
		tex = d->n_data;
	else if (d->wall_dir == 'S')
		tex = d->s_data;
	else if (d->wall_dir == 'W')
		tex = d->w_data;
	else
		tex = d->e_data;
	color = tex[d->tex_y * d->img_w + d->tex_x];
	my_mlx_pixel_put(d, x, y, color);
}

void	render_vertical(t_struct *data, int x, float height, double wall_hit) // CA NORMALEMENT C BON
{
	double	start;
	double	end;
	double	step;

	start = (data->sc_h - height) / 2;
	end = start + height;
	step = (double)data->img_h / height;
	double (pos) = 0;
	data->tex_x = (int)(wall_hit * (double)data->img_w);
	int (y) = 0;
	while (y < data->sc_h)
	{
		if (y < start)
			my_mlx_pixel_put(data, x, y, 0x0080FF);
		else if (y >= start && y < end)
		{
			apply_texture(data, x, y, pos);
			pos = pos + step;
		}
		else
			my_mlx_pixel_put(data, x, y, 0x500050);
		y++;
	}
}

void	draw_collumn(t_struct *data, int x, double distance, double wall_hit)
{
	float	height;

	height = data->sc_h / distance;
	if (distance <= 0)
		height = data->sc_h;
	render_vertical(data, x, height, wall_hit);
}

int	get_wall_dir(t_struct *data, double x, double y)
{
	double	delta_x;
	double	delta_y;

	delta_x = x - (int)x;
	delta_y = y - (int)y;
	if (delta_y < 1e-6)
		data->wall_dir = 'N';
	else if (delta_y > 1 - 1e-6)
		data->wall_dir = 'S';
	else if (delta_x < 1e-6)
		data->wall_dir = 'W';
	else
		data->wall_dir = 'E';
	return (1);
}

double	check_ray(t_struct *data, double ray_angle, double *wall_hit)
{
	double	distance;
	double	x;
	double	y;

	distance = 0.0;
	while (distance < data->ray_len)
	{
		x = data->player_x + cos(ray_angle) * distance;
		y = data->player_y + sin(ray_angle) * distance;
		if ((int)x < data->height[(int)y] && (int)y < data->map_h)
		{
			if (data->map[(int)y][(int)x] == '1' && get_wall_dir(data, x, y))
			{
				if (cos(ray_angle) > sin(ray_angle))
					*wall_hit = x - (int)x;
				else
					*wall_hit = y - (int)y;
				return (distance * cos(ray_angle - data->player_x_dir));
			}
		}
		else
			break ;
		distance = distance + 0.01;
	}
	return (-1);
}

void	init_rays(t_struct *data)
{
	double	distance;
	double	ray_angle;
	double	step;
	double	wall_hit;
	int		x;

	step = data->fov / (double)data->sc_w;
	ray_angle = data->player_x_dir - (data->fov / 2);
	x = 0;
	while (ray_angle < data->player_x_dir + (data->fov / 2))
	{
		distance = check_ray(data, ray_angle, &wall_hit);
		if (distance != -1)
			draw_collumn(data, x, distance, wall_hit);
		ray_angle = ray_angle + step;
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
