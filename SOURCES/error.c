#include "cub3d.h"

int	ft_close(t_struct *data)
{
	mlx_destroy_image(data->mlx, data->north_img);
	mlx_destroy_image(data->mlx, data->south_img);
	mlx_destroy_image(data->mlx, data->west_img);
	mlx_destroy_image(data->mlx, data->east_img);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free(data->file);
	ft_free(data->map);
	free(data->path_to_N);
	free(data->path_to_S);
	free(data->path_to_W);
	free(data->path_to_E);
	free(data->height);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_print_error_and_exit(char *s)
{
	printf("Error\n%s\n", s);
	exit(EXIT_FAILURE);
}

void	ft_error_and_exit(char *s, t_struct *data)
{
	ft_free(data->file);
	ft_free(data->map);
	printf("Error\n%s\n", s);
	exit(EXIT_FAILURE);
}
