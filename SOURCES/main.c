#include "cub3d.h"

int	deal_key(int key, t_struct *data)
{
	if (key == 65307)
		ft_close(data);
	else if (key == W || key == A || key == S || key == D)
		change_position(data, data->p, key);
	else if (key == L_ARROW || key == R_ARROW)
		change_direction(data, data->p, key);
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	test_map(t_struct *data)
{
	int		i;

	i = 0;
	data->map = malloc(sizeof(char *) * (10 + 1));
	while (i < 10)
	{
		if (i == 0 || i == 9)
			data->map[i] = ft_strdup("1111111111");
		else if (i == 5)
			data->map[i] = ft_strdup("10000N0001");
		else
			data->map[i] = ft_strdup("1000000001");
		i++;
	}
	data->map[i] = NULL;
	data->map_h = 10;
	data->map_w = 10;
	data->spawn_x = 5;
	data->spawn_y = 5;
	data->spawn_dir = 'N';
}

int	main(int argc, char **argv)
{
	t_struct	*data;

	data = NULL;
	(void)argc;
	(void)argv;
	// if (ft_check_arg(argv) == BAD)
	// 	ft_error_and_exit("Wrong number of args", data);
	data = init_data();
	if (!data)
		ft_error_and_exit("Malloc error of data", data);
	test_map(data);
	if (init_player(data) == BAD)
		ft_error_and_exit("Malloc error of player", data);
	printf("p->x_dir = %d\n", data->p->x_dir);
	printf("p->y_dir = %d\n", data->p->y_dir);
	init_rays(data, data->p);
	mlx_key_hook(data->graph->win, deal_key, data);
	mlx_hook(data->graph->win, 17, 1L << 17, ft_close, data);
	mlx_loop(data->graph->mlx);
}
