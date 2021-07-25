/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:04:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/25 19:01:43 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode)
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

int	main(int ac, char **av)
{
	
	t_vars	*vars;
	
	if (ac < 2 || ac > 2)
		__exit__("Error\nargument Error\n", NULL, FAILURE);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->mouv= malloc(sizeof(t_mouv));
	if (!vars->mouv)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->key = init_key();
	if (!vars->key)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	parsing(av[1], vars);
	vars->img = malloc(sizeof(t_img));
	if (!vars->img)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->mlx = mlx_init(); 
	if (!vars->mlx)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->win = mlx_new_window(vars->mlx, 1000, 1000, "Hello world!");  //创建带名字的窗口
	if (!vars->win)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->img->img = mlx_new_image(vars->mlx, 1000, 1000);       //创建图片
	if (!vars->img->img)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	tex_all(vars);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_len, //取得图片地址
								&vars->img->endian);
	vars->img->width = WIDTH;
	vars->img->height = HEIGHT;
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->win, RED_CROSS, 1L << 2, __close__, vars); //鼠标点叉叉
	mlx_loop_hook(vars->mlx, event_loop, vars);  //循环事件
	mlx_loop(vars->mlx);   //持续运行
}