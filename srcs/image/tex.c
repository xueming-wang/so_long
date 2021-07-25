/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 13:11:08 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/25 16:49:32 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

# define TEX_PLAYER "./tex/knight.xpm"
# define TEX_WALL "./tex/wall.xpm"
# define TEX_COLLECT "./tex/key.xpm"
# define TEX_EXIT "./tex/closed_door.xpm"
# define TEX_ZERO "./tex/floor.xpm"



void  set_tex(char *path, t_vars *vars, t_img *tex)
{
	const int fd = open(path, O_RDONLY);
	
	if (fd < 0)
		__exit__("path Error\n", vars, FAILURE);
		
	tex->img = mlx_xpm_file_to_image(vars->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		__exit__("path Error\n", vars, FAILURE);
	//把地址生成图片 1个图片
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel, 
							&tex->line_len, &tex->endian);
	//获取图片指针地址
}

void  tex_all(t_vars *vars)
{ 

	set_tex(TEX_PLAYER, vars, &vars->tex[0]);
	set_tex(TEX_WALL, vars, &vars->tex[1]);
	set_tex(TEX_COLLECT, vars, &vars->tex[2]);
	set_tex(TEX_EXIT, vars, &vars->tex[3]);
	set_tex(TEX_ZERO, vars, &vars->tex[4]);
}
// typedef struct	s_img {
// 	void	*img;  //图片
// 	char	*addr; //指针地址
	  
// 	int		bits_per_pixel;  //=32  一个点有4个char， 8bit)每个像数的字节数 : the number of bits per pixels.
// 	int		height;  
// 	int		width;
// 	int 	line_len;//宽度1000* 4 （4个char)一行的字节数 the size of a line times 4.
// 	int  	endian;  
// }				t_img;
