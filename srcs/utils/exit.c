/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:08:05 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/26 20:15:28 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  _free_(void *vars)
{
	if (vars)
		free(vars);
	vars = NULL;	
}

#if defined(__APPLE__) && defined(__MACH__)
void destroy_img(t_vars *vars)
{
	int i;
	if (vars->mlx)
	{
		if (vars->img)
		{
			mlx_destroy_image(vars->mlx, vars->img->img);
			_free_(vars->img);
		}
		i = 0;
		while (i < 5)
			mlx_destroy_image(vars->mlx, vars->tex[i++].img);
		
		mlx_destroy_window(vars->mlx, vars->win);
		_free_(vars->mlx);
	}
	
}
#else 
void destroy_img(t_vars *vars)
{
	int i;
	if (vars->mlx)
	{
		if (vars->img)
		{
			mlx_destroy_image(vars->mlx, vars->img->img);
			_free_(vars->img);
		}
		i = 0;
		while (i < 5)
			mlx_destroy_image(vars->mlx, vars->tex[i++].img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		_free_(vars->mlx);
	}
}

#endif


void  free_vars(t_vars *vars)
{
	int i;
	if (vars)
	{
		destroy_img(vars);
		if (vars->key)
			 _free_(vars->key);
		if (vars->mouv)
		 	_free_(vars->mouv);
		i = 0;
		if (vars->map)
		{
			while (vars->map[i])
				_free_(vars->map[i++]);
			_free_(vars->map);
		}

		_free_(vars);
	}
}

int	__exit__(char *msg, t_vars *vars, int ret)
{
	if (msg)
		ft_putstr(msg);
	free_vars(vars);
	exit(ret);
}
