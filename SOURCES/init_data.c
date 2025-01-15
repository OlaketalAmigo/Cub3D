#include "cub3d.h"

int	graphic_init(t_graph **g, t_struct *d)
{
	(*g) = malloc(sizeof(t_graph));
	if (!(*g))
		return (BAD);
	(*g)->mlx = mlx_init();
	if (!(*g)->mlx)
		return (BAD);
	(*g)->win = mlx_new_window((*g)->mlx, d->sc_w, d->sc_h, "Cub3D");
	if (!(*g)->win)
		return (BAD);
	(*g)->img = mlx_new_image((*g)->mlx, d->sc_w, d->sc_h);
	if (!(*g)->img)
		return (BAD);
	(*g)->addr = mlx_get_data_addr((*g)->img, &(*g)->bpp,
			&(*g)->length, &(*g)->end);
	if (!(*g)->addr)
		return (BAD);
	return (GOOD);
}

t_struct	*init_data(void)
{
	t_struct	*data;

	data = malloc(sizeof(t_struct));
	if (!data)
		return (NULL);
	data->graph = NULL;
	data->map = NULL;
	data->sc_h = 800;
	data->sc_w = 1200;
	data->fov = 72;
	data->ray_len = 100;
	data->fov = 0.66;
	data->map_h = 0;
	data->map_w = 0;
	data->spawn_x = 0;
	data->spawn_y = 0;
	data->spawn_dir = 0;
	if (graphic_init(&data->graph, data) == BAD)
		return (NULL);
	return (data);
}
