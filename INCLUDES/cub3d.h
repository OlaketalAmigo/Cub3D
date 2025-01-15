/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfauve-p <tfauve-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:35:14 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/15 13:59:24 by tfauve-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "stdio.h"
# include "stdlib.h"
# include "readline/readline.h"
# include "readline/history.h"
# include "asm/termbits.h"
# include "sys/ioctl.h"
# include "signal.h"
# include "unistd.h"
# include "fcntl.h"
# include "sys/types.h"
# include "sys/wait.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define GOOD 0
# define BAD 1
# define YES 0
# define NO 1
# define ERROR_ARGS_NUMBER "Error\nWrong number of args\n"
# define ERROR_MAP_FORMAT "Error\nWrong map format, you must use *.cub file\n"
# define ERROR_MAP_FILE_OPEN "Error\nCouldn't open map's file"
# define ERROR_OPEN "Error\nCouldn't open map's file\n"
# define ERROR_MALLOC_FAILED "Error\nMalloc failed\n"
# define ERROR_FILE_MISSING "Error\nOne texture's path is missing\n"
# define ERROR_FILE_DUPLICATE "Error\nToo much path for one texture\n"
# define ERROR_FILE_OPEN "Error\nCouldn't open textures file\n"
# define ERROR_FILE_CEILING "Error\nSomething wrong with ceiling\n"
# define ERROR_FILE_FLOOR "Error\nSomething wrong with floor\n"
# define ERROR_FILE_SPACES "Error\nFile's element can't be separated by spaces\n"
# define ERROR_MAP_ONE_BLOCK "Error\nMap can't be separated by newlines\n"
# define ERROR_MAP_WRONG_CHAR "Error\nMap contains invalid characters\n"
# define ERROR_MAP_BORDER "Error\nMap must be cornered by walls '1'\n"
# define ERROR_MAP_TOO_MANY_PLAYER "Error\nMap has too many player\n"
# define ERROR_MAP_MISSING_ENTRY "Error\nMap must have at least one entry\n"

typedef struct data
{
	int		a;
	char	*string;
	char	**file;
	char	**map;
	int		floor_first;
	int		floor_second;
	int		floor_third;
	int		ceiling_first;
	int		ceiling_second;
	int		ceiling_third;
}	t_struct;

// ERROR //

void	ft_print_error_and_exit(char *s);

// PARSER //

int		ft_parser(t_struct *data, int argc, char **argv);

// PARSER UTILS //

int		ft_check_map_format(char **argv);
int		ft_check_textures(t_struct *data);
int		ft_check_textures_missing(t_struct *data);
int		ft_check_textures_duplicate(t_struct *data);
int		ft_check_file(t_struct *data);

// PARSER UTILS 2 //

int		ft_check_texture_file_opening(t_struct *data, char *s);
int		ft_check_texture_file_missing(t_struct *data, char *s);
int		ft_check_texture_file_duplicate(t_struct *data, char *s);

// PARSER UTILS 3 //

int		ft_check_floor(t_struct *data, char *s);
int		ft_check_ceiling(t_struct *data, char *s);

// PARSER UTILS 4 //

int		ft_check_upper_wall(char *string);
int		ft_check_whitespace_line(char **argv);
int		ft_check_cornered_by_walls(t_struct *data);

// PARSER UTILS 5 //

int		ft_check_map_characters(t_struct *data, int i, int *count);
int		ft_check_map(t_struct *data);

// TOOLS 1 //

char	*ft_get_path(char *string);
void	ft_printf_tab(char **tab);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_remove_space(char *string);
char	*ft_strdup(char *string);

// TOOLS 2 //

char	*ft_fill_map(char *string);
int		ft_check_one_block(t_struct *data);
char	*ft_put_number_to_string(char *string, int n);
int		ft_nb_arg(char **tab);

// GET NEXT LINE //

int		ft_read_line(int fd, char **stock);
char	*get_next_line(int fd);

// GET NEXT LINE UTILS //

int		ft_strlen(char *s);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_to_keep(char *string);
char	*ft_to_return(char *string);

// FREE //

void	ft_free(char **tab);

// TRIM //

int		ft_check(char const c, char const *set);
int		ft_start(char const *s1, char const *set);
int		ft_end(char const *s1, char const *set, int length);
char	*ft_strtrim(char *s1, char *set);

#endif