#include "cub3d.h"

void	change_direction(t_struct *data, int key)
{
	if (key == R_ARROW)
		data->player_x_dir = data->player_x_dir + 0.1;
	else if (key == L_ARROW)
		data->player_x_dir = data->player_x_dir - 0.1;
	if (data->player_x_dir >= 2 * M_PI)
		
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->sc_w, data->sc_h);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->len, &data->end);
	init_rays(data);
}

int	assign_next_pos(t_struct *data, int key, char c)
{
	if (c == 'x')
	{
		if (key == W)
			return (data->player_x + cos(data->player_x_dir));
		else if (key == A)
			return (data->player_x - sin(data->player_x_dir));
		else if (key == S)
			return (data->player_x - cos(data->player_x_dir));
		else if (key == D)
			return (data->player_x + sin(data->player_x_dir));
	}
	else
	{
		if (key == W)
			return (data->player_y + sin(data->player_x_dir));
		else if (key == A)
			return (data->player_y + cos(data->player_x_dir));
		else if (key == S)
			return (data->player_y - sin(data->player_x_dir));
		else if (key == D)
			return (data->player_y - cos(data->player_x_dir));
	}
	return (0);
}

int	check_next_pos(t_struct *d, int key)
{
	int	t_x;
	int	t_y;

	t_x = assign_next_pos(d, key, 'x');
	t_y = assign_next_pos(d, key, 'y');
	if (d->map_w < t_x || d->map_h < t_y || d->map[t_y][t_x] == ' '
		|| d->map[t_y][t_x] == '1')
		return (BAD);
	return (GOOD);
}

void	change_position(t_struct *data, int key)
{
	if (check_next_pos(data, key) == BAD)
		return ;
	data->player_x = assign_next_pos(data, key, 'x');
	data->player_y = assign_next_pos(data, key, 'y');
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->sc_w, data->sc_h);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->len, &data->end);
	init_rays(data);
}
