#include "cub3d.h"

void	change_direction(t_struct *data, t_p *p, int key)
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
	mlx_destroy_image(data->graph->mlx, data->graph->img);
	data->graph->img = mlx_new_image(data->graph->mlx, data->sc_w, data->sc_h);
	data->graph->addr = mlx_get_data_addr(data->graph->img,
			&data->graph->bpp, &data->graph->length, &data->graph->end);
	init_rays(data, p);
}

int	assign_next_pos(t_p *p, int key, char c)
{
	if (c == 'x')
	{
		if (key == W)
			return (p->x_pos + p->x_dir);
		else if (key == A)
			return (p->x_pos - p->y_dir);
		else if (key == S)
			return (p->x_pos - p->x_dir);
		else if (key == D)
			return (p->x_pos + p->y_dir);
	}
	else
	{
		if (key == W)
			return (p->y_pos + p->y_dir);
		else if (key == A)
			return (p->y_pos + p->x_dir);
		else if (key == S)
			return (p->y_pos - p->y_dir);
		else if (key == D)
			return (p->y_pos - p->x_dir);
	}
	return (0);
}

int	check_next_pos(t_struct *d, t_p *p, int key)
{
	int	t_x;
	int	t_y;

	t_x = assign_next_pos(p, key, 'x');
	t_y = assign_next_pos(p, key, 'y');
	if (d->map_w < t_x || d->map_h < t_y || d->map[t_y][t_x] == ' '
		|| d->map[t_y][t_x] == '1')
		return (BAD);
	return (GOOD);
}

void	change_position(t_struct *data, t_p *p, int key)
{
	if (check_next_pos(data, p, key) == BAD)
		return ;
	p->x_pos = assign_next_pos(p, key, 'x');
	p->y_pos = assign_next_pos(p, key, 'y');
	mlx_destroy_image(data->graph->mlx, data->graph->img);
	data->graph->img = mlx_new_image(data->graph->mlx, data->sc_w, data->sc_h);
	data->graph->addr = mlx_get_data_addr(data->graph->img,
			&data->graph->bpp, &data->graph->length, &data->graph->end);
	init_rays(data, p);
}
