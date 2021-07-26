/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:17:39 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/25 19:36:54 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* Put a pixel on the screen */
void	pixel_put_color(t_vars *vars, int x, int y, unsigned int color)    //找到点 放上颜色
{
	char	*dst;

	dst = vars->img->addr + (y * vars->img->line_len + x * (vars->img->bits_per_pixel / 8));   //addr图片地址
	*(unsigned int*)dst = color;
}

void draw_one_pixe(t_vars *vars, int i, int x_index, int y_index)  // i表示是第几个图片
{
	const double pixe_x = ((double)1000 / vars->map_x_len); //横着每个格子的长度
	const double pixe_y = ((double)1000 / vars->map_y_len); //竖着每个格子的长度
	char *addr;
	double x; 
	double y = 0.0;  //x y 是图片地址图像的点的位置
	
	while (y < pixe_y)  //画了一个蓝色的格子
	{
    	x = 0.0;
		while (x < pixe_x)
		{ //把对应点的颜色放在新的方块里
			addr = vars->tex[i].addr;//取一个图片地址 从0 开始
			addr += (size_t)((y / pixe_y) * vars->tex[i].height) * vars->tex[i].line_len;
						//格子里y的值占格子长度的百分比位置 * 图片的高度 （得到点的颜色）* 一行的长度
			addr += (size_t)((x /pixe_x) * vars->tex[i].width) * 4;   //(vars->tex[i].bits_per_pixel / 8);
					 	//格子里x的值占格子长度的百分比位置 * 图片的宽度（得到这个点） * 一个点的长度  （加起来就是这个点的地址颜色）；
    		pixel_put_color(vars,  x + (x_index * pixe_x),  y + (y_index * pixe_y), *(unsigned int *)addr);//画点的位置
    		x++;
		}
		y++;
	}
}

void draw_map(t_vars *vars)
{
	int y = 0;
	int x;

	while (vars->map[y])
	{
    	x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				draw_one_pixe(vars, 2, x, y);
			else if (vars->map[y][x] == 'E')
				draw_one_pixe(vars, 3, x, y);
			else if (vars->map[y][x] == '1')
				draw_one_pixe(vars, 1, x, y);
			else if (vars->map[y][x] == '0')
				draw_one_pixe(vars, 4, x, y);
      		x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0); //上传图片到窗口
}

void	draw_player(t_vars *vars)
{
	draw_one_pixe(vars, 0, vars->mouv->x, vars->mouv->y); 
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0); //上传图片到窗口
}
