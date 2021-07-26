/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:04:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/26 19:43:00 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	event_quit(t_vars *vars)
{
	__exit__(NULL, vars, SUCCESS);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	*vars;
	
	if (ac < 2 || ac > 2)
		__exit__("Error\nargument Error\n", NULL, FAILURE);
	vars = ft_calloc(sizeof(t_vars), 1);
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
	vars->win = mlx_new_window(vars->mlx, 1000, 1000, "so_long");  //创建带名字的窗口
	if (!vars->win)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->img->img = mlx_new_image(vars->mlx, 1000, 1000);       //创建图片
	if (!vars->img->img)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	tex_all(vars);
	/* Gets the data address of the current image.*/
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_len, //取得图片地址
								&vars->img->endian);
	
	vars->img->width = WIDTH;
	vars->img->height = HEIGHT;
	vars->counter = 0;
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->win, RED_CROSS, 1L << 2, event_quit, vars); //鼠标点叉叉
	 /*Hook into each loop.*/
	mlx_loop_hook(vars->mlx, event_loop, vars);  //循环事件
	/* Loop over the given mlx pointer */
	mlx_loop(vars->mlx); 
}
