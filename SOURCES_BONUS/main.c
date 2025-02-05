#include "cub3d.h"

int	mouse_move(int x, int y, t_struct *data)
{
	static int	prev_x = 0;

	(void)y;
	if (x == prev_x)
		return (0);
	if (x > prev_x)
		change_direction(data, R_ARROW);
	else
		change_direction(data, L_ARROW);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->sc_w, data->sc_h);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->len, &data->end);
	init_rays(data);
	prev_x = x;
	return (0);
}

int	key_release(int key, t_struct *data)
{
	if (key == W)
		data->w = NO;
	else if (key == A)
		data->a = NO;
	else if (key == S)
		data->s = NO;
	else if (key == D)
		data->d = NO;
	else if (key == L_ARROW)
		data->l_arrow = NO;
	else if (key == R_ARROW)
		data->r_arrow = NO;
	return (0);
}

int	key_press(int key, t_struct *data)
{
	if (key == ESCAPE)
		ft_close(data);
	if (key == W)
		data->w = YES;
	else if (key == A)
		data->a = YES;
	else if (key == S)
		data->s = YES;
	else if (key == D)
		data->d = YES;
	else if (key == L_ARROW)
		data->l_arrow = YES;
	else if (key == R_ARROW)
		data->r_arrow = YES;
	return (0);
}

int	game_loop(t_struct *data)
{
	if (data->w == YES)
		data->movement += change_position(data, W);
	if (data->a == YES)
		data->movement += change_position(data, A);
	if (data->s == YES)
		data->movement += change_position(data, S);
	if (data->d == YES)
		data->movement += change_position(data, D);
	if (data->l_arrow == YES)
		data->movement += change_direction(data, L_ARROW);
	if (data->r_arrow == YES)
		data->movement += change_direction(data, R_ARROW);
	if (data->movement >= 1 || data->start == 0)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, data->sc_w, data->sc_h);
		data->addr = mlx_get_data_addr(data->img,
				&data->bpp, &data->len, &data->end);
		init_rays(data);
		data->movement = 0;
		data->start = 1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	data;

	data.img_h = 48;
	data.img_w = 48;
	ft_parser(&data, argc, argv);
	if (init_data(&data) == BAD)
		ft_error_and_exit(ERROR_MALLOC_FAILED, &data);
	ft_init_mlx(&data);
	init_rays(&data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.win, 17, 1L << 17, ft_close, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_move, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
