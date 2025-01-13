#include "cub3d.h"

char	*ft_put_number_to_string(char *string, int n)
{
	int		i;
	int		j;
	int		k;
	int		dodged;
	char	*to_return;

	i = 0;
	dodged = 0;
	while(++i != -1 && string[i] && dodged < n)
	{
		if (string[i] == 44)
			dodged++;
	}
	j = i;
	while(string[i] && string[i] != 44 )
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

int	ft_is_valid_number(t_struct *data, char	*string, char *input, char c)
{
	int	nb;

	if (ft_strlen(input) >= 4)
		return (BAD);
	nb = atoi(input);
	if (nb < 0 ||  nb > 255)
		return (BAD);
	if (ft_strncmp(string,"first", 5) == GOOD && c == 102)
		data->F1 = nb;
	if (ft_strncmp(string,"second", 6) == GOOD && c == 102)
		data->F2 = nb;
	if (ft_strncmp(string,"third", 5) == GOOD && c == 102)
		data->F3 = nb;
	if (ft_strncmp(string,"first", 5) == GOOD && c == 99)
		data->C1 = nb;
	if (ft_strncmp(string,"second", 6) == GOOD && c == 99)
		data->C2 = nb;
	if (ft_strncmp(string,"third", 5) == GOOD && c == 99)
		data->C3 = nb;
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
		return (free(string), free(first), free(second), free(third), BAD);
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
	if (ft_is_valid_number(data, "first", first, 'f') == BAD)
		return (free(first), free(second), free(third), BAD);
	if (ft_is_valid_number(data, "second", second, 'f') == BAD)
		return (free(first), free(second), free(third), BAD);
	if (ft_is_valid_number(data, "third", third, 'f') == BAD)
		return (free(string), free(first), free(second), free(third), BAD);
	return (free(first), free(second), free(third), GOOD);
}

int	ft_check_floor(t_struct *data, char *s)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (data->file[i])
	{
		trimmed = ft_strtrim(data->file[i], " ");
		trimmed = ft_remove_space(trimmed);
		if (ft_strncmp(trimmed, s, 1) == GOOD)
		{
			if (ft_check_floor_values(data, trimmed) == BAD)
				return (free(trimmed), BAD);
			else
				return (free(trimmed), GOOD);
		}
		free(trimmed);
		i++;
	}
	return (BAD);
}

int	ft_check_ceiling(t_struct *data, char *s)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (data->file[i])
	{
		trimmed = ft_strtrim(data->file[i], " ");
		trimmed = ft_remove_space(trimmed);
		if (ft_strncmp(trimmed, s, 1) == GOOD)
		{
			if (ft_check_ceiling_values(data, trimmed) == BAD)
				return (free(trimmed), BAD);
			else
				return (free(trimmed), GOOD);
		}
		free(trimmed);
		i++;
	}
	return (BAD);
}
