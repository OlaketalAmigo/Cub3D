/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:59:55 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/06 13:59:56 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_path(char *string)
{
	char	*to_return;
	int		i;
	int		j;

	i = 2;
	if (string)
	{
		while (string[i])
			i++;
		to_return = malloc (1 * (i));
		if (to_return)
		{
			i = 1;
			j = -1;
			while (++j != -1 && string[++i])
				to_return[j] = string[i];
			to_return[j] = '\0';
			free(string);
			return (to_return);
		}
	}
	return (NULL);
}

char	*ft_strdup(char *string)
{
	int		i;
	char	*to_return;

	if (!string)
		return (NULL);
	i = ft_strlen(string);
	to_return = malloc (i + 1);
	if (!to_return)
		return (NULL);
	i = -1;
	while (string[++i])
	{
		to_return[i] = string[i];
	}
	to_return[i] = '\0';
	return (to_return);
}

void	ft_printf_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}
	printf("Done printing tab\n");
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (BAD);
	while (i < n)
	{
		if (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
		else
			return (BAD);
	}
	return (GOOD);
}

char	*ft_remove_space(char *string)
{
	char	*to_return;

	int (i) = -1;
	int (k) = -1;
	int (j) = 0;
	int (l) = -1;
	if (!string)
		return (NULL);
	while (string[++i])
	{
		if (string[i] != 32)
			j++;
	}
	to_return = malloc (j + 1);
	if (!to_return)
		return (NULL);
	while (++k <= i)
	{
		if (string[k] != 32)
			to_return[++l] = string[k];
	}
	to_return[l] = '\0';
	free(string);
	return (to_return);
}
