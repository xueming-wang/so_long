/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:17:59 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/20 17:28:43 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define  SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
#include <fcntl.h>
# include "libft.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define SUCCESS 0
# define FAILURE 1



typedef struct s_check
{
	int		read;
	char	*line;
	int		len;
	int		prev_len;
	int		fd;
	int		i;
}   t_check;

typedef struct	s_img {
	void	*img;
	char	*addr;
	  
	int		bits_per_pixel;  //=32 (4个char 8bit)每个像数的字节数
	int		height;  
	int		width;
	int 	line_len;//宽度512* 4 （4个char)一行的字节数
	int  endian;  //0或者1
}				t_img;

typedef struct s_mouv
{
    int x;
    int y;
}         t_mouv;

typedef struct s_key
{
    int a;
    int w;
    int s;
    int d;
}         t_key;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int	map_x_len;
	int	map_y_len;
	t_key 	*key;
	t_mouv *mouv;
	t_img *img;
	
	
}				t_vars;

int     check_is_file(char **av);
void	quit_error(char *msg, char *line);
int		event_loop(t_vars *vars);

int key_press(int keycode, t_vars *vars);
int key_release(int keycode, t_vars *vars);
int	key_hook(int keycode, t_vars *vars);
t_key  *init_key(void);
int	__close__(t_vars *vars);
void	__exit__(char *msg, t_vars *vars, int ret);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void draw_pixe(t_vars *vars);
void draw_pixe(t_vars *vars);
t_check check_is_map(char *av);

#endif