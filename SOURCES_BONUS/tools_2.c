/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:59:57 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/10 14:13:17 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_fill_map(char *string)
{
	int		i;
	char	*to_return;

	if (!string)
		return (NULL);
	i = ft_strlen(string);
	to_return = malloc (i + 2);
	if (!to_return)
		return (NULL);
	i = -1;
	while (string[++i])
		to_return[i] = string[i];
	to_return[i] = '\n';
	to_return[i + 1] = '\0';
	return (to_return);
}

char	*ft_put_number_to_string(char *string, int n)
{
	int		i;
	int		j;
	int		k;
	int		dodged;
	char	*to_return;

	i = 0;
	dodged = 0;
	while (++i != -1 && string[i] && dodged < n)
	{
		if (string[i] == 44)
			dodged++;
	}
	j = i;
	while (string[i] && string[i] != 44)
		i++;
	to_return = malloc (i - j + 1);
	if (!to_return)
		return (NULL);
	k = 0;
	while (j < i)
		to_return[k++] = string[j++];
	to_return[k] = '\0';
	return (to_return);
}

int	ft_nb_arg(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_init(t_struct *data)
{
	data->img_h = 96;
	data->img_w = 96;
	data->map = NULL;
	data->file = NULL;
	data->path_to_n = NULL;
	data->path_to_s = NULL;
	data->path_to_w = NULL;
	data->path_to_e = NULL;
}
