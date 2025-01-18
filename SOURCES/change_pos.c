#include "cub3d.h"

void	change_direction(t_struct *data, int key)
{
	if (key == R_ARROW)
		data->player_x_dir = data->player_x_dir + 0.1;
	else if (key == L_ARROW)
		data->player_x_dir = data->player_x_dir - 0.1;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->sc_w, data->sc_h);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->len, &data->end);
	init_rays(data);
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
	int		x; // a repasser en double plus tard avec la nouvelle map
	int		y; // bis

	assign_next_pos(&t_x, &t_y, key, d->player_x_dir);
	t_x = d->player_x + t_x;
	t_y = d->player_y + t_y;
	x = floor(t_x);
	y = floor(t_y);
	if (x < 0 || y < 0 || x >= d->map_w || y >= d->map_h
		|| d->map[y][x] == ' ' || d->map[y][x] == '1')
		return (BAD);
	d->player_x = t_x;
	d->player_y = t_y;
	return (GOOD);
}

void	change_position(t_struct *data, int key)
{
	if (check_next_pos(data, key) == BAD)
		return ;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->sc_w, data->sc_h);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->len, &data->end);
	init_rays(data);
}
