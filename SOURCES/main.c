#include "cub3d.h"

int	deal_key(int key, t_struct *data)
{
	if (key == 65307)
		ft_close(data);
	else if (key == W || key == A || key == S || key == D)
		change_position(data, data->p, key);
	else if (key == L_ARROW || key == R_ARROW)
		change_direction(data->p, key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	*data;

	data = NULL;
	(void)argc;
	(void)argv;
	if (ft_check_arg(argv) == BAD)
		ft_error_and_exit("Wrong number of args", data);
	if (init_data(data) == BAD)
		ft_error_and_exit("Malloc error of data", data);
	if (init_player(data) == BAD)
		ft_error_and_exit("Malloc error of player", data);
	init_rays(data, data->p);
	mlx_key_hook(data->graph->win, deal_key, data);
	mlx_hook(data->graph->win, 17, 1L << 17, ft_close, &data);
	mlx_loop(data->graph->mlx);
}
