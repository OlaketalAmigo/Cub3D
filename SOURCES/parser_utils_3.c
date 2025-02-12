/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:58:36 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/02/12 11:59:58 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_valid_number(t_struct *data, char	*string, char *input, char c)
{
	int	nb;

	if (ft_strlen(input) >= 4)
		return (BAD);
	nb = ft_atoi(input);
	if (nb < 0 || nb > 255 || (nb == 0 && ft_strlen(input) == 0))
		return (BAD);
	if (ft_strncmp(string, "first", 5) == GOOD && c == 99)
		data->c_first = nb;
	if (ft_strncmp(string, "second", 6) == GOOD && c == 99)
		data->c_second = nb;
	if (ft_strncmp(string, "third", 5) == GOOD && c == 99)
		data->c_third = nb;
	if (ft_strncmp(string, "first", 5) == GOOD && c == 102)
		data->f_first = nb;
	if (ft_strncmp(string, "second", 6) == GOOD && c == 102)
		data->f_second = nb;
	if (ft_strncmp(string, "third", 5) == GOOD && c == 102)
		data->f_third = nb;
	return (GOOD);
}

int	ft_check_floor_values(t_struct *data, char *string)
{
	int		count;
	char	*first;
	char	*second;
	char	*third;

	int (i) = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == 44)
			count++;
		i++;
	}
	if (count != 2)
		return (BAD);
	first = ft_put_number_to_string(string, 0);
	second = ft_put_number_to_string(string, 1);
	third = ft_put_number_to_string(string, 2);
	if (ft_is_valid_number(data, "first", first, 'f') == BAD)
		return (free(first), free(second), free(third), BAD);
	if (ft_is_valid_number(data, "second", second, 'f') == BAD)
		return (free(first), free(second), free(third), BAD);
	if (ft_is_valid_number(data, "third", third, 'f') == BAD)
		return (free(first), free(second), free(third), BAD);
	return (free(first), free(second), free(third), GOOD);
}

int	ft_check_ceiling_values(t_struct *data, char *string)
{
	int		count;
	char	*first;
	char	*second;
	char	*third;

	int (i) = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == 44)
			count++;
		i++;
	}
	if (count != 2)
		return (BAD);
	first = ft_put_number_to_string(string, 0);
	second = ft_put_number_to_string(string, 1);
	third = ft_put_number_to_string(string, 2);
	if (ft_is_valid_number(data, "first", first, 'c') == BAD)
		return (free(first), free(second), free(third), BAD);
	if (ft_is_valid_number(data, "second", second, 'c') == BAD)
		return (free(first), free(second), free(third), BAD);
	if (ft_is_valid_number(data, "third", third, 'c') == BAD)
		return (free(first), free(second), free(third), BAD);
	return (free(first), free(second), free(third), GOOD);
}

int	ft_check_floor(t_struct *data, char *s)
{
	int		i;
	int		found;
	char	*trimmed;

	i = 0;
	found = 0;
	while (data->file[i])
	{
		trimmed = ft_strtrim(data->file[i], " ");
		trimmed = ft_remove_space(trimmed);
		if (ft_strncmp(trimmed, s, 1) == GOOD)
		{
			if (ft_check_floor_values(data, trimmed) == BAD)
				return (free(trimmed), BAD);
			if (found == 1)
				return (free(trimmed), BAD);
			found++;
		}
		free(trimmed);
		i++;
	}
	if (found == 1)
		return (GOOD);
	return (BAD);
}

int	ft_check_ceiling(t_struct *data, char *s)
{
	int		i;
	int		found;
	char	*trimmed;

	i = 0;
	found = 0;
	while (data->file[i])
	{
		trimmed = ft_strtrim(data->file[i], " ");
		trimmed = ft_remove_space(trimmed);
		if (ft_strncmp(trimmed, s, 1) == GOOD)
		{
			if (ft_check_ceiling_values(data, trimmed) == BAD)
				return (free(trimmed), BAD);
			if (found == 1)
				return (free(trimmed), BAD);
			found++;
		}
		free(trimmed);
		i++;
	}
	if (found == 1)
		return (GOOD);
	return (BAD);
}
