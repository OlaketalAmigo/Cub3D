#include "cub3d.h"

void	deal_key(int key, t_struct *data, t_p *p)
{
	if (key == ESC)
		ft_close(data, p);
	else if (key == W || key == A || key == S || key == D)
		change_position(data, p, key);
	else if (key == L_ARROW || key == R_ARROW)
		change_direction(p, key);
}

int	main(int argc, char **argv)
{
	t_struct	*data;
	t_p			*p;

	if (ft_check_arg(argv) == BAD)
		ft_error_and_exit("Wrong number of args");
	if (init_prog(data) == BAD)
		ft_error_and_exit("Malloc error of data");
	if (init_player(data, p) == BAD)
		ft_error_and_exit("Malloc error of player");
	init_rays(data, p);
	mlx_key_hook(data->graph.win, deal_key, data);
	mlx_hook(data->graph.win, 17, 1L << 17, ft_close, data);
	mlx_loop(data->graph.mlx);
}
