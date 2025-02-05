#include "cub3d.h"

int	get_color(t_struct *d, char c)
{
	if (c == 'F')
		return (d->f_first << 16 | d->f_second << 8 | d->f_third);
	else if (c == 'C')
		return (d->c_first << 16 | d->c_second << 8 | d->c_third);
	return (0);
}

void	apply_texture(t_struct *d, int x, int y, double pos)
{
	uint32_t	*tex;
	int			offset;

	d->tex_y = (int)pos % d->img_h;
	if (d->tex_x < 0)
		d->tex_x = 0;
	else if (d->tex_x >= d->img_w)
		d->tex_x = d->img_w - 1;
	if (d->tex_y < 0)
		d->tex_y = 0;
	else if (d->tex_y >= d->img_h)
		d->tex_y = d->img_h - 1;
	if (d->wall_dir == 'N')
		tex = (uint32_t *)d->n_data;
	else if (d->wall_dir == 'S')
		tex = (uint32_t *)d->s_data;
	else if (d->wall_dir == 'W')
		tex = (uint32_t *)d->w_data;
	else
		tex = (uint32_t *)d->e_data;
	offset = (d->tex_y * d->img_w + d->tex_x);
	if (offset >= 0 && offset < d->img_h * d->img_w)
		my_mlx_pixel_put(d, x, y, tex[offset]);
}

void	get_wall_dir(t_struct *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			data->wall_dir = 'E';
		else
			data->wall_dir = 'W';
	}
	else
	{
		if (ray->step_y > 0)
			data->wall_dir = 'S';
		else
			data->wall_dir = 'N';
	}
}

void	ft_get_textures(t_struct *data)
{
	data->n_data = mlx_get_data_addr(data->north_img,
			&data->bpp, &data->len, &data->end);
	data->s_data = mlx_get_data_addr(data->south_img,
			&data->bpp, &data->len, &data->end);
	data->w_data = mlx_get_data_addr(data->west_img,
			&data->bpp, &data->len, &data->end);
	data->e_data = mlx_get_data_addr(data->east_img,
			&data->bpp, &data->len, &data->end);
	if (!data->n_data || !data->s_data || !data->w_data || !data->e_data)
		ft_error_and_exit("ERROR_TEXTURE_FAILED", data);
}

void	ft_init_mlx(t_struct *data)
{
	int	i;

	data->north_img = mlx_xpm_file_to_image(data->mlx, data->path_to_n,
			&data->img_w, &data->img_h);
	data->south_img = mlx_xpm_file_to_image(data->mlx, data->path_to_s,
			&data->img_w, &data->img_h);
	data->east_img = mlx_xpm_file_to_image(data->mlx, data->path_to_e,
			&data->img_w, &data->img_h);
	data->west_img = mlx_xpm_file_to_image(data->mlx, data->path_to_w,
			&data->img_w, &data->img_h);
	ft_get_textures(data);
	data->height = malloc (4 * ft_nb_arg(data->map));
	if (data->height)
	{
		i = 0;
		while (data->map[i])
		{
			data->height[i] = ft_strlen(data->map[i]);
			i++;
		}
	}
}
