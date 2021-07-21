/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:17:39 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/21 19:20:37 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)    //找到点 放上颜色
{
	char	*dst;

	dst = vars->img->addr + (y * vars->img->line_len + x * (vars->img->bits_per_pixel / 8));   //addr图片地址
	*(unsigned int*)dst = color;
}

void draw_one_pixe(t_vars *vars, int color)
{
	int pixe_x = (1000 / vars->map_x_len); //横着每个格子的长度
	int pixe_y = (1000 / vars->map_y_len); //竖着每个格子的长度
	
	double x  = 0.0; 
	double y;
	
	while (x < pixe_x)  //画了一个蓝色的格子
	{
    	y = 0.0;
		while (y < pixe_y)
		{
    		my_mlx_pixel_put(vars,  x,  y,  color);
    		y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0); //上传图片到窗口
}

//img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
void draw_map(t_vars *vars)
{
	int x = 0;
	int y;

	while (vars->map[x])
	{
		//printf("%s\n", vars->map[0]);
    	y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == 'C')
			{
				//printf("%c\n", vars->map[x][y]);
				draw_one_pixe(vars, 0x00800000);
			}
			else if (vars->map[x][y] == 'P')
			{
				printf("%c\n", vars->map[x][y]);
				draw_one_pixe(vars, 0x00F08080);
			}
			else if (vars->map[x][y] == 'E')
			{
				draw_one_pixe(vars, 0x0090EE90);
			}
			else if (vars->map[x][y] == '1')
			{
				draw_one_pixe(vars, 0x00006400);
			}
			else if (vars->map[x][y] == '0')
			{
				draw_one_pixe(vars, 0x007FFF00);
			}
      		y++;
		}
		x++;
	}
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0); //上传图片到窗口
}

// void draw_pixe(t_vars *vars)
// {
  
//   // (X position * 4 + 4 * Line size * Y position)  像数的地址指针
//   //my_mlx_pixel_put(vars, x, y, 0x000000FF) 找到点放上颜色
//    int x_i = 0;
// 	 int y_i;  
// 	while ((vars->mouv->x) + x_i  < 100 + vars->mouv->x)
// 	{

// 		y_i = 0;
// 		while ((vars->mouv->y) + y_i  < 100 + vars->mouv->y)
// 		{
     
   // my_mlx_pixel_put(vars,  vars->mouv->x + x_i,  vars->mouv->y + y_i, 0x00000000);
//       y_i += 1;
		
// 			 //找到点放上颜色
// 		}
// 		x_i += 1;
// 	}
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0); //上传图片到窗口
	
// 	 //mlx_key_hook(vars->win, key_hook, vars);  //键盘设置
                            
// }
