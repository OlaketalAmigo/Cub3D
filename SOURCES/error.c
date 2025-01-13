#include "cub3d.h"

void	ft_close(t_struct *data, t_p *p)
{
	mlx_destroy_image(data->graph.mlx, data->graph.img);
	mlx_destroy_window(data->graph.mlx, data->graph.win);
	mlx_destroy_display(data->graph.mlx);
	free(data->graph.mlx);
	ft_free(data->map);
	free(data);
	free(p);
	exit(EXIT_SUCCESS);
}

void	ft_error_and_exit(char *s, t_struct *data, t_p *p)
{
	if (data)
	{
		mlx_destroy_image(data->graph.mlx, data->graph.img);
		mlx_destroy_window(data->graph.mlx, data->graph.win);
		mlx_destroy_display(data->graph.mlx);
		free(data->graph.mlx);
		ft_free(data->map);
		free(data);
	}
	if (p)
		free(p);
	printf("%s\n", s);
	exit(EXIT_FAILURE);
}
