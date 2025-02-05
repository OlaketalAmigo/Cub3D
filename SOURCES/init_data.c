#include "cub3d.h"

int	graphic_init(t_struct *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (BAD);
	data->win = mlx_new_window(data->mlx, data->sc_w, data->sc_h, "Cub3D");
	if (!data->win)
		return (mlx_destroy_display(data->mlx), BAD);
	data->img = mlx_new_image(data->mlx, data->sc_w, data->sc_h);
	if (!data->img)
		return (mlx_destroy_window(data->mlx, data->win),
			mlx_destroy_display(data->mlx), BAD);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->len, &data->end);
	if (!data->addr)
		return (mlx_destroy_image(data->mlx, data->img),
			mlx_destroy_window(data->mlx, data->win),
			mlx_destroy_display(data->mlx), BAD);
	return (GOOD);
}

int	init_dir(t_struct *data, int dir)
{
	if (dir == 'N')
	{
		data->player_x_dir = M_PI / 2;
		return (GOOD);
	}
	else if (dir == 'S')
	{
		data->player_x_dir = 3 * M_PI / 2;
		return (GOOD);
	}
	else if (dir == 'W')
	{
		data->player_x_dir = M_PI;
		return (GOOD);
	}
	else if (dir == 'E')
	{
		data->player_x_dir = 0;
		return (GOOD);
	}
	return (BAD);
}

int	init_data(t_struct *data)
{
	data->sc_h = 800;
	data->sc_w = 1200;
	data->fov = 72 * (M_PI / 180);
	data->ray_len = 30;
	data->player_x = data->spawn_x + 0.5;
	data->player_y = data->spawn_y + 0.5;
	data->w = NO;
	data->a = NO;
	data->s = NO;
	data->d = NO;
	data->l_arrow = NO;
	data->r_arrow = NO;
	if (init_dir(data, data->spawn_dir) == BAD)
		return (BAD);
	if (graphic_init(data) == BAD)
		return (BAD);
	if (init_minimap(data, data) == BAD)
		return (BAD);
	return (GOOD);
}
