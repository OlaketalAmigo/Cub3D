/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:23:08 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/15 11:26:15 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		k;

	k = -1;
	string = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!string)
		return (NULL);
	while (++k < ft_strlen(s1))
		string[k] = s1[k];
	k = -1;
	while (++k < ft_strlen(s2))
		string[ft_strlen(s1) + k] = s2[k];
	string[ft_strlen(s1) + k] = '\0';
	free(s1);
	free(s2);
	return (string);
}

char	*ft_to_keep(char *string)
{
	int		i;
	int		k;
	char	*newstring;

	i = 0;
	k = 0;
	if (!string)
		return (NULL);
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	newstring = malloc (sizeof(char) * (ft_strlen(string) - i + 1));
	if (!newstring)
		return (NULL);
	while (string[i++] != '\0')
		newstring[k++] = string[i];
	newstring[k] = '\0';
	if (ft_strchr(string, '\n') == 1)
		free(string);
	if (newstring[0] == '\0')
	{
		free(newstring);
		return (NULL);
	}
	return (newstring);
}

char	*ft_to_return(char *string)
{
	int		i;
	int		j;
	char	*newstring;

	i = 0;
	j = -1;
	if (!string)
		return (NULL);
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (i == ft_strlen(string))
		return (string);
	newstring = malloc (sizeof(char) * (i + 1));
	if (!newstring)
		return (NULL);
	while (string[++j] != '\n')
		newstring[j] = string[j];
	newstring[j] = '\0';
	return (newstring);
}
