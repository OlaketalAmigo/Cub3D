#include "cub3d.h"

void	change_direction(t_p *p, int key)
{
	double	tmp;

	tmp = p->x_dir;
	if (key == L_ARROW)
	{
		p->x_dir = p->x_dir * cos(0.1) - p->y_dir * sin(0.1);
		p->y_dir = tmp * sin(0.1) + p->y_dir * cos(0.1);
	}
	else if (key == R_ARROW)
	{
		p->x_dir = p->x_dir * cos(-0.1) - p->y_dir * sin(-0.1);
		p->y_dir = tmp * sin(-0.1) + p->y_dir * cos(-0.1);
	}
}

void	change_position(t_p *p, int key)
{
	if (key == W)
	{
		p->x_pos = p->x_pos + p->x_dir;
		p->y_pos = p->y_pos + p->y_dir;
	}
	else if (key == A)
	{
		p->x_pos = p->x_pos - p->y_dir;
		p->y_pos = p->y_pos + p->x_dir;
	}
	else if (key == S)
	{
		p->x_pos = p->x_pos - p->x_dir;
		p->y_pos = p->y_pos - p->y_dir;
	}
	else if (key == D)
	{
		p->x_pos = p->x_pos + p->y_dir;
		p->y_pos = p->y_pos - p->x_dir;
	}
}

void	deal_key(int key, t_struct *data, t_p *p)
{
	if (key == ESC)
		ft_close(data, p);
	else if (key == W || key == A || key == S || key == D)
		change_position(p, key);
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
	if (init_camera(data) == BAD)
		ft_error_and_exit("Malloc error of camera");
	init_rays(data, p);
	mlx_key_hook(data->graph.win, deal_key, data);
	mlx_hook(data->graph.win, 17, 1L << 17, ft_close, data);
	mlx_loop(data->graph.mlx);
	printf("SALAM\n");
}
