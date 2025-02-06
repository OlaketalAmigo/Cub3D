/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:58:18 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/06 13:58:19 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free(data->path_to_n);
	free(data->path_to_s);
	free(data->path_to_w);
	free(data->path_to_e);
	free(data->height);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_textures(t_struct *data)
{
	if (data->north_img)
		mlx_destroy_image(data->mlx, data->north_img);
	if (data->south_img)
		mlx_destroy_image(data->mlx, data->south_img);
	if (data->east_img)
		mlx_destroy_image(data->mlx, data->east_img);
	if (data->west_img)
		mlx_destroy_image(data->mlx, data->west_img);
	if (data->path_to_n)
		free(data->path_to_n);
	if (data->path_to_s)
		free(data->path_to_s);
	if (data->path_to_e)
		free(data->path_to_e);
	if (data->path_to_w)
		free(data->path_to_w);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	ft_print_error_and_exit(char *s)
{
	printf("%s", s);
	exit(EXIT_FAILURE);
}

void	ft_error_and_exit(char *s, t_struct *data)
{
	ft_free(data->file);
	ft_free(data->map);
	printf("%s", s);
	exit(EXIT_FAILURE);
}
