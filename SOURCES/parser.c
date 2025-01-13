#include "cub3d.h"

int	ft_count_line(char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = open(argv[1], O_RDONLY);
	if (i == -1)
		ft_print_error_and_exit("Coulnd't open map's file");
	j = 0;
	tmp = get_next_line(i);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(i);
		j++;
	}
	close (i);
	return (j);
}

void	ft_set_up_cub3d_file(t_struct *data, char **argv)
{
	char	*string;
	int		nb_line;
	int		fd;
	int		i;

	nb_line = ft_count_line(argv);
	data->file = malloc(8 * (nb_line + 1));
	if (data->file)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (free(data->file), ft_print_error_and_exit("Could'nt open map's file"));
		string = get_next_line(fd);
		i = -1;
		while (++i != -1 && string)
		{
			data->file[i] = string;
			string = get_next_line(fd);
		}
		data->file[i] = NULL;
		close(fd);
	}
	else
		ft_print_error_and_exit("Malloc failed");
}


void	ft_parser(t_struct *data, int argc, char **argv)
{
	if (argc != 2)
        ft_print_error_and_exit("Wrong number of args");
	if (ft_check_map_format(argv) == BAD)
		ft_print_error_and_exit("Wrong map format, you must use *.cub file");
	ft_set_up_cub3d_file(data, argv);
	if (ft_check_map(data) == BAD)
	{
		ft_free(data->file);
		exit(EXIT_FAILURE);
	}
}
