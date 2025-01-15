/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:23:17 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/15 14:19:48 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_struct	data;

	ft_parser(&data, argc, argv);
	printf("Actual map is :\n");
	ft_printf_tab(data.map);
	ft_free(data.file);
	ft_free(data.map);
	return (0);
}
