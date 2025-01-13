#include "cub3d.h"

int	graphic_init(t_struct *data)
{
	t_graph	*g;

	g = malloc(sizeof(t_graph));
	if (!g)
		return (BAD);
	g->mlx = mlx_init();
	if (!g->mlx)
		return (BAD);
	g->win = mlx_new_window(g->mlx, data->screen_w, data->screen_h, "Cub3D");
	if (!g->win)
		return (BAD);
	g->img = mlx_new_image(g->mlx, data->screen_w, data->screen_h);
	if (!g->img)
		return (BAD);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_length, &g->endian);
	if (!g->addr)
		return (BAD);
	data->graph = *g;
	return (GOOD);
}

int	init_data(t_struct *data)
{
	data = malloc(sizeof(t_struct));
	if (!data)
		return (BAD);
	data->map = NULL;
	data->string = NULL;
	data->fov = 0.66;
	data->ray_len = 100;
	data->screen_h = 800;
	data->screen_w = 1200;
	data->map_h = 0;
	data->map_w = 0;
	if (graphic_init(data) == BAD)
		return (BAD);
	return (GOOD);
}
