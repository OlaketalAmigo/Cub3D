#include "cub3d.h"

void	get_minimap_scale(t_struct *data, int *h, int *w)
{
	*h = 200 / data->map_h;
	*w = 200 / data->map_w;
}

void	draw_grid(t_struct *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	h;
	int	w;

	i = 0;
	h = data->mini_h;
	w = data->mini_w;
	if (x * w >= 200 || y * h >= 200)
		return ;
	while (i < data->mini_h)
	{
		j = 0;
		while (j < data->mini_w)
		{
			if ((x * w) + j < 200 && (y * h) + i < 200)
				my_mlx_pixel_put(data, (x * w) + j, (y * h) + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_struct *d)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 200)
	{
		x = 0;
		while (x < 200)
		{
			color = 0x000000;
			if (y < d->map_h && x < d->height[y])
			{
				if (d->map[y][x] == '0' || d->map[y][x] > 50)
					color = 0xFFFFFF;
				else if (d->map[y][x] == '1')
					color = 0x00FF00;
			}
			draw_grid(d, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_struct *d, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (x + i < 200 && y + j < 200)
				my_mlx_pixel_put(d, x + i, y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	render_minimap(t_struct *d)
{
	int	x;
	int	y;
	int	p_x;
	int	p_y;

	y = 0;
	get_minimap_scale(d, &d->mini_h, &d->mini_w);
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
	draw_map(d);
	p_x = (d->player_x * d->mini_w) - 2;
	p_y = (d->player_y * d->mini_h) - 2;
	draw_player(d, p_x, p_y);
}
