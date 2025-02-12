/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:58:59 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/12 12:15:24 by tfauve-p         ###   ########.fr       */
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

int	ft_atoi(char *string)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (string[i])
	{
		if (string[i] == 48 || string[i] == 49 || string[i] == 50
			|| string[i] == 51 || string[i] == 52 || string[i] == 53
			|| string[i] == 54 || string[i] == 55 || string[i] == 56
			|| string[i] == 57)
			nb = nb * 10 + (string[i] - 48);
		else
			return (-1);
		i++;
	}
	return (nb);
}
