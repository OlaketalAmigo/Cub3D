#include "cub3d.h"

void	get_minimap_scale(t_struct *data, int *h, int *w)
{
	*h = 200 / data->map_h;
	*w = 200 / data->map_w;
}

void	draw_map(t_struct *d, int h, int w)
{
	int	x;
	int	y;

	y = 0;
	while (y < 200)
	{
		x = 0;
		while (x < 200)
		{
			if (y < d->map_h && x < d->height[y])
			{
				if (d->map[y][x] == '0' || d->map[y][x] > 50)
					my_mlx_pixel_put(d, x * w, y * h, 0xFFFFFF);
				else if (d->map[y][x] == '1')
					my_mlx_pixel_put(d, x * w, y * h, 0x00FF00);
			}
			x++;
		}
		y++;
	}
}

void	render_minimap(t_struct *d)
{
	int	x;
	int	y;
	int	h;
	int	w;

	y = 0;
	get_minimap_scale(d, &h, &w);
	while (y < 200)
	{
		x = 0;
		while (x < 200)
		{
			my_mlx_pixel_put(d, x, y, 0x000000);
			x++;
		}
		y++;
	}
	draw_map(d, h, w);
	my_mlx_pixel_put(d, d->player_x * w, d->player_y * h, 0xFF0000);
}
