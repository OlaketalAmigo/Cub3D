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

# define GOOD 0
# define BAD 1
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
	int		line_length;
	int		endian;
}	t_graph;

typedef struct data
{
	char	**map;
	char	*string;
	double	fov;
	int		ray_len;
	int		screen_h;
	int		screen_w;
	int		map_h;
	int		map_w;
	int		spawn_x;
	int		spawn_y;
	int		spawn_dir;
	t_graph	*graph;
	t_p		*p;

}	t_struct;

// PARSER //

int		ft_check_arg(char **argv);

// PARSER UTILS //

// INIT DATA //

int		init_data(t_struct *data);
int		graphic_init(t_struct *data);

// INIT PLAYER //

int		init_player(t_struct *data);

// RAYCASTING //

void	init_rays(t_struct *data, t_p *p);
void	draw_collumn(t_struct *data, int x, double distance);
void	render_vertical(t_struct *data, int x, int height);
void	my_mlx_pixel_put(t_graph *graph, int x, int y, int color);
double	check_ray(t_struct *data, t_p *p, double ray_angle);

// CHANGE POSITION //

void	change_direction(t_p *p, int key);
void	change_position(t_struct *data, t_p *p, int key);
int		check_next_pos(t_struct *d, t_p *p, int key);
int		assign_next_pos(t_p *p, int key, char c);

// ERRORS //

void	ft_error_and_exit(char *str, t_struct *data);
int		ft_close(t_struct *data);
void	ft_free(char **tab);

#endif