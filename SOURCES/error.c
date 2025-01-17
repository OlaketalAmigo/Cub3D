/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprunet <gprunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:23:01 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/17 11:46:40 by gprunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_struct *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free(data->file);
	ft_free(data->map);
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
