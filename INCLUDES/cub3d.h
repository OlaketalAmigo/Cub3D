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

typedef struct data
{
	int		a;
	char	*string;
	char	**file;
}	t_struct;

#endif

// ERROR //

void	ft_print_error_and_exit(char *s);

// PARSER //

void	ft_parser(t_struct *data, int argc, char **argv);

// PARSER UTILS //

int		ft_check_map_format(char **argv);
int		ft_check_textures(t_struct *data);
int		ft_check_textures_missing(t_struct *data);
int		ft_check_textures_duplicate(t_struct *data);
int		ft_check_map(t_struct *data);

// PARSER UTILS 2 //

int		ft_check_texture_file_opening(t_struct *data, char *s);
int		ft_check_texture_file_missing(t_struct *data, char *s);
int		ft_check_texture_file_duplicate(t_struct *data, char *s);

// PARSER UTILIS 3 //

int		ft_check_floor(t_struct *data);
int		ft_check_ceiling(t_struct *data);

// TOOLS 1 //

char	*ft_get_path(char *string);
void	ft_printf_tab(char **tab);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_remove_space(char *string);

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