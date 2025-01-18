/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehe <hehe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:23:17 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/18 18:00:28 by hehe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	deal_key(int key, t_struct *data)
{
	if (key == ESCAPE)
		ft_close(data);
	else if (key == W || key == A || key == S || key == D)
		change_position(data, key);
	else if (key == L_ARROW || key == R_ARROW)
		change_direction(data, key);
	return (0);
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
	t_struct	data;

	ft_parser(&data, argc, argv);
	// printf("Actual map is :\n");
	// ft_printf_tab(data.map);
	if (init_data(&data) == BAD)
		ft_error_and_exit("Malloc error of data", &data);
	// test_map(&data);	// Map 10X10 avec N au milieu
	init_rays(&data);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_hook(data.win, 17, 1L << 17, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
