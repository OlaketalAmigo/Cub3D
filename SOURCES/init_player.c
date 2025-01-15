#include "cub3d.h"

int	init_player(t_struct *data)
{

	data->p = malloc(sizeof(t_p));
	if (!data->p)
		return (BAD);
	data->p->x_pos = data->spawn_x;
	data->p->y_pos = data->spawn_y;
	if (data->spawn_dir == 'N' || data->spawn_dir == 'S')
	{
		data->p->x_dir = 0;
		data->p->y_dir = -1;
		if (data->spawn_dir == 'S')
			data->p->y_dir = 1;
	}
	else if (data->spawn_dir == 'W' || data->spawn_dir == 'E')
	{
		data->p->x_dir = -1;
		if (data->spawn_dir == 'E')
			data->p->x_dir = 1;
		data->p->y_dir = 0;
	}
	return (GOOD);
}
