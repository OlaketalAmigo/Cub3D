/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehe <hehe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:35:14 by tfauve-p          #+#    #+#             */
/*   Updated: 2025/01/15 16:34:02 by hehe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
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

# define GOOD 1
# define BAD 0
# define W 119
# define A 97
# define S 115
# define D 100
# define L_ARROW 65361
# define R_ARROW 65363

typedef struct s_p
{
	int		x_pos;
	int		y_pos;
	int		x_dir;
	int		y_dir;
}	t_p;

typedef struct s_graphic
{
	char	*addr;
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		length;
	int		end;
}	t_graph;

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
# define ERROR_FILE_ELEMENT_ORDER "Error\nElement's order is wrong\n"
# define ERROR_MAP_ONE_BLOCK "Error\nMap can't be separated by newlines\n"
# define ERROR_MAP_WRONG_CHAR "Error\nMap contains invalid characters\n"
# define ERROR_MAP_BORDER "Error\nMap must be cornered by walls '1'\n"
# define ERROR_MAP_TOO_MANY_PLAYER "Error\nMap has too many player\n"
# define ERROR_MAP_MISSING_ENTRY "Error\nMap must have at least one entry\n"

typedef struct data
{
	char	**file;
	char	**map;
	int		floor_first;
	int		floor_second;
	int		floor_third;
	int		ceiling_first;
	int		ceiling_second;
	int		ceiling_third;
	double	fov;
	int		ray_len;
	int		sc_h;
	int		sc_w;
	int		map_h;
	int		map_w;
	int		spawn_x;
	int		spawn_y;
	int		spawn_dir;
	t_graph	*graph;
	t_p		*p;

}	t_struct;

// ERROR //

void	ft_print_error_and_exit(char *s);
void	ft_error_and_exit(char *s, t_struct *data);
int		ft_close(t_struct *data);

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

int		ft_is_valid_number(t_struct *data, char	*string, char *input, char c);
int		ft_check_floor_values(t_struct *data, char *string);
int		ft_check_ceiling_values(t_struct *data, char *string);
int		ft_check_floor(t_struct *data, char *s);
int		ft_check_ceiling(t_struct *data, char *s);

// PARSER UTILS 4 //

int		ft_check_whitespace_line(char **tab);
int		ft_check_upper_wall(char *string);
int		ft_check_one_block(t_struct *data);
int		ft_check_border(t_struct *data, int i);
int		ft_check_cornered_by_walls(t_struct *data);

// PARSER UTILS 5 //

int		ft_check_map_characters(t_struct *data, int i, int *count);
int		ft_check_map(t_struct *data);
int		ft_check_element_order(char	**tab);
void	ft_fill_order_tab(int *check, int i, char **tab);
void	ft_replace_characters(char **tab, char s, char c);

// TOOLS 1 //

char	*ft_get_path(char *string);
char	*ft_strdup(char *string);
void	ft_printf_tab(char **tab);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_remove_space(char *string);

// TOOLS 2 //

char	*ft_fill_map(char *string);
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

// INIT DATA //

int		init_data(t_struct *data);
int		graphic_init(t_graph **g, t_struct *d);

// INIT PLAYER //

int		init_player(t_struct *data);

// RAYCASTING //

void	init_rays(t_struct *data, t_p *p);
void	draw_collumn(t_struct *data, int x, double distance);
void	render_vertical(t_struct *data, int x, int height);
void	my_mlx_pixel_put(t_graph *graph, int x, int y, int color);
double	check_ray(t_struct *data, t_p *p, double ray_angle);

// CHANGE POSITION //

void	change_direction(t_struct *data, t_p *p, int key);
void	change_position(t_struct *data, t_p *p, int key);
int		check_next_pos(t_struct *d, t_p *p, int key);
int		assign_next_pos(t_p *p, int key, char c);

// ERRORS //

void	ft_error_and_exit(char *str, t_struct *data);
int		ft_close(t_struct *data);
void	ft_free(char **tab);

#endif