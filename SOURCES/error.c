#include "cub3d.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_close(t_struct *data)
{
	mlx_destroy_image(data->graph->mlx, data->graph->img);
	mlx_destroy_window(data->graph->mlx, data->graph->win);
	mlx_destroy_display(data->graph->mlx);
	free(data->graph->mlx);
	free(data->graph);
	ft_free(data->map);
	free(data->p);
	free(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_error_and_exit(char *s, t_struct *data)
{
	if (data)
	{
		if (data->graph)
		{
			mlx_destroy_image(data->graph->mlx, data->graph->img);
			mlx_destroy_window(data->graph->mlx, data->graph->win);
			mlx_destroy_display(data->graph->mlx);
			free(data->graph->mlx);
			free(data->graph);
		}
		if (data->p)
			free(data->p);
		ft_free(data->map);
		free(data);
	}
	printf("%s\n", s);
	exit(EXIT_FAILURE);
}
