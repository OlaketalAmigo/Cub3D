#include "cub3d.h"

int	ft_is_valid_number(t_struct *data, char	*string, char *input, char c)
{
	int	nb;

	if (ft_strlen(input) >= 4)
		return (BAD);
	printf("input = %s\n", input);
	nb = atoi(input);
	printf("nb = %d\n", nb);
	if (nb < 0 || nb > 255)
		return (BAD);
	if (ft_strncmp(string, "first", 5) == GOOD && c == 99)
		data->ceiling_first = nb;
	if (ft_strncmp(string, "second", 6) == GOOD && c == 99)
		data->ceiling_second = nb;
	if (ft_strncmp(string, "third", 5) == GOOD && c == 99)
		data->ceiling_third = nb;
	if (ft_strncmp(string, "first", 5) == GOOD && c == 102)
		data->floor_first = nb;
	if (ft_strncmp(string, "second", 6) == GOOD && c == 102)
		data->floor_second = nb;
	if (ft_strncmp(string, "third", 5) == GOOD && c == 102)
		data->floor_third = nb;
	printf("C1 = %d\n", data->ceiling_first);
	printf("C2 = %d\n", data->ceiling_second);
	printf("C3 = %d\n", data->ceiling_third);
	printf("F1 = %d\n", data->floor_first);
	printf("F2 = %d\n", data->floor_second);
	printf("F3 = %d\n", data->floor_third);
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
