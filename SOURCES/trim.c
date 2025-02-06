/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:59:01 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/06 13:59:02 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (GOOD);
		i++;
	}
	return (BAD);
}

int	ft_start(char const *s1, char const *set)
{
	int	x;

	x = 0;
	while (ft_check(s1[x], set) == GOOD)
		x++;
	return (x);
}

int	ft_end(char const *s1, char const *set, int length)
{
	int	y;

	y = length - 1;
	if (s1 && set && y > 0)
	{
		while (y > 0 && ft_check(s1[y], set) == GOOD)
			y--;
		return (y);
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*string;
	int		debut;
	int		fin;
	int		i;
	int		length;

	if (!s1 || !set)
		return (NULL);
	i = -1;
	length = ft_strlen(s1);
	if (length == 0)
		return (NULL);
	debut = ft_start(s1, set);
	fin = ft_end(s1, set, length);
	if (fin - debut <= 0)
		string = malloc(1);
	else
		string = malloc (fin - debut + 2);
	if (!string)
		return (NULL);
	while (debut + (++i) <= fin)
		string[i] = s1[debut + i];
	string[i] = '\0';
	return (string);
}
