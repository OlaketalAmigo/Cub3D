#include "cub3d.h"

int	init_player(t_struct *data, t_p *p)
{
	p = malloc(sizeof(t_p));
	if (!p)
		return (BAD);
	p->x_pos = data->spawn_x;
	p->y_pos = data->spawn_y;
	if (data->spawn_dir == 'N' || data->spawn_dir == 'S')
	{
		p->x_dir = 0;
		p->y_dir = -1;
		if (data->spawn_dir == 'S')
			p->y_dir = 1;
	}
	else if (data->spawn_dir == 'W' || data->spawn_dir == 'E')
	{
		p->x_dir = -1;
		if (data->spawn_dir == 'E')
			p->x_dir = 1;
		p->y_dir = 0;
	}
	return (GOOD);
}
