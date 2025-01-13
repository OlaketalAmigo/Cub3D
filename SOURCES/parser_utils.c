#include "cub3d.h"

int	ft_check_map_format(char **argv)
{
	int	i;
	
	i = ft_strlen(argv[1]);
	if (i <= 3)
		return (BAD);
	if (argv[1][i - 1] != 98)
		return (BAD);
	if (argv[1][i - 2] != 117)
		return (BAD);
	if (argv[1][i - 3] != 99)
		return (BAD);
	if (argv[1][i - 4] != 46)
		return (BAD);
	return (GOOD);
}
int	ft_check_textures(t_struct *data)
{
	if (ft_check_texture_file_opening(data, "NO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_opening(data, "SO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_opening(data, "WE ") == BAD)
		return (BAD);
	if (ft_check_texture_file_opening(data, "EA ") == BAD)
		return (BAD);
	return (GOOD);
}

int	ft_check_textures_missing(t_struct *data)
{
	if (ft_check_texture_file_missing(data, "NO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_missing(data, "SO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_missing(data, "WE ") == BAD)
		return (BAD);
	if (ft_check_texture_file_missing(data, "EA ") == BAD)
		return (BAD);
	return (GOOD);
}

int	ft_check_textures_duplicate(t_struct *data)
{
	if (ft_check_texture_file_duplicate(data, "NO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_duplicate(data, "SO ") == BAD)
		return (BAD);
	if (ft_check_texture_file_duplicate(data, "WE ") == BAD)
		return (BAD);
	if (ft_check_texture_file_duplicate(data, "EA ") == BAD)
		return (BAD);
	return (GOOD);
}

int	ft_check_map(t_struct *data)
{
	if (ft_check_textures_missing(data) == BAD)
		return (printf("Error : One texture's path is missing\n"), BAD);
	if (ft_check_textures(data) == BAD)
		return (printf("Error : Couldn't open textures file\n"), BAD);
	if (ft_check_textures_duplicate(data) == BAD)
		return (printf("Error : Too much path for one texture\n"),BAD);
	if (ft_check_floor(data) == BAD)
		return (printf("Error : Something wrong with floor\n"), BAD);
	if (ft_check_ceiling(data) == BAD)
		return (printf("Error : Something wrong with ceiling\n"), BAD);
	return (GOOD);
}
