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
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define GOOD 1
# define BAD 0
# define W 119
# define A 97
# define S 115
# define D 100
# define ESCAPE 65307
# define L_ARROW 65361
# define R_ARROW 65363

# define YES 0
# define NO 1
# define ERROR_ARGS_NUMBER "Error\nWrong number of args\n"
# define ERROR_TEXTURE_FAILED "Error\nSomething wrong with textures files\n"
# define ERROR_MAP_FORMAT "Error\nWrong map format, you must use *.cub file\n"
# define ERROR_MAP_FILE_OPEN "Error\nCouldn't open map's file\n"
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
	char		**file;
	char		**map;
	char		*addr;
	int			img_h;
	int			img_w;
	int			*height;
	char		*path_to_n;
	char		*path_to_s;
	char		*path_to_w;
	char		*path_to_e;
	void		*north_img;
	void		*south_img;
	void		*west_img;
	void		*east_img;
	char		*n_data;
	char		*s_data;
	char		*w_data;
	char		*e_data;
	int			tex_x;
	int			tex_y;
	char		wall_dir;
	int			f_first;
	int			f_second;
	int			f_third;
	int			c_first;
	int			c_second;
	int			c_third;
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			end;
	int			len;
	int			mini_w;
	int			mini_h;
	int			w;
	int			a;
	int			s;
	int			d;
	int			l_arrow;
	int			r_arrow;
	double		fov;
	double		ray_len;
	int			sc_h;
	int			sc_w;
	int			map_h;
	int			map_w;
	int			spawn_x;
	int			spawn_y;
	int			spawn_dir;
	double		player_x;
	double		player_y;
	double		player_x_dir;
	int			movement;
	int			start;
}	t_struct;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	int		side;
	double	wall_x;
	double	distance;
}	t_ray;

// ERROR //

void	ft_print_error_and_exit(char *s);
void	ft_error_and_exit(char *s, t_struct *data);
void	ft_free_textures(t_struct *data);
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
int		graphic_init(t_struct *d);

// RAYCASTING //

void	init_rays(t_struct *data);
void	draw_collumn(t_struct *data, int x, double distance, double wall_hit);
void	render_vertical(t_struct *data, int x, float height, double wall_hit);
void	my_mlx_pixel_put(t_struct *data, int x, int y, int color);
double	check_ray(t_struct *data, double ray_angle, double *wall_hit);

// DDA ALGO //

void	init_struct_ray(t_ray *ray, t_struct *data, double ray_angle);
void	dda_step(t_ray *ray);
double	final_distance(t_ray *ray, t_struct *d, double ray_a, double *wall_h);
int		is_border(t_struct *data, int x, int y);

// WALL TEX //

void	apply_texture(t_struct *data, int x, int y, double pos);
void	get_wall_dir(t_struct *data, t_ray *ray);
void	ft_get_textures(t_struct *data);
void	ft_init_mlx(t_struct *data);
int		get_color(t_struct *data, char c);

// MINIMAP //

void	render_minimap(t_struct *data);

// CHANGE POSITION //

int		change_direction(t_struct *data, int key);
int		change_position(t_struct *data, int key);
void	assign_next_pos(double *x, double *y, int key, double dir);
int		wall_pos_right(t_struct *d, double t_x, double t_y);
int		wall_pos_left(t_struct *d, double t_x, double t_y);

// ERRORS //

void	ft_error_and_exit(char *str, t_struct *data);
int		ft_close(t_struct *data);
void	ft_free(char **tab);

#endif