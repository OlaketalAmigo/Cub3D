#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_struct data;

	ft_parser(&data, argc, argv);
	printf("Hasta luego luchao gringolito!\n");
	ft_free(data.file);
	return (0);
}
