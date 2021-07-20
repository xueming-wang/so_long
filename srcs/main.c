/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:04:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/20 17:28:23 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)    //找到点 放上颜色
{
	char	*dst;

	dst = vars->img->addr + (y * vars->img->line_len + x * (vars->img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode== 13)
		printf("IS W\n");
	if (keycode== 0)
		printf("IS A\n");
	if (keycode== 1)
		printf("IS S\n");
	if (keycode== 2)
		printf("IS D\n");
	return (0);
	
}

int	__close__(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	__exit__(NULL, vars, SUCCESS);
	return 1;	
}

int	main(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		__exit__("Error malloc\n", vars, FAILURE);
	vars->img = malloc(sizeof(t_img));
	if (!vars->img)
		__exit__("Error malloc\n", vars, FAILURE);
	vars->mouv= malloc(sizeof(t_mouv));
	if (!vars->mouv)
		__exit__("Error malloc\n", vars, FAILURE);
	vars->mlx = mlx_init(); 
	if (!vars->mlx)
		__exit__("Error malloc\n", vars, FAILURE);
	vars->win = mlx_new_window(vars->mlx, 1000, 1000, "Hello world!");  //创建带名字的窗口
	if (!vars->win)
		__exit__("Error malloc\n", vars, FAILURE);
	vars->img->img = mlx_new_image(vars->mlx, 1000, 1000);       //创建图片
	if (!vars->img->img)
		__exit__("Error malloc\n", vars, FAILURE);
		
    vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_len, //取得图片地址
								&vars->img->endian);
	vars->key = init_key();
	if (!vars->key)
		__exit__("Error malloc\n", vars, FAILURE);
    // int x = 50;
	// int y ;
	// while (x < 100)
	// {
	// 	y = 50;
	// 	while (y < 100)
	// 	{
	// 		my_mlx_pixel_put(vars, x, y, 0x000000FF);
	// 		y++; //找到点放上颜色
	// 	}
	// 	++x;
	// }
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0); //上传图片到窗口
	
	// mlx_key_hook(vars->win, key_hook, vars);  //键盘设置
	
	vars->mouv->x = 100;
	vars->mouv->y = 100;

	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->win, 17, 1L << 2, __close__, vars); //鼠标点叉叉
	
	mlx_loop_hook(vars->mlx, event_loop, vars);
		
	mlx_loop(vars->mlx);   //持续运行
}

// func2_draw(stzong)
// {
//         const int bianchang = 5
//         int x_i;
//         int y_i;

//         x_i = 0;
//         while (x + x_i < fangkuai + x)
//         {
//             y_i = 0;
//             while (y + y_i < fangkuai + y)
//             {
//                 y_i++;
//                 my_mlx_pixel_put(&imgptr, x+x_i, y+y_i, BLUE);
//             }
//             x_i++;
//         }
// }
