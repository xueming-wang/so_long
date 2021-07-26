/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:08:05 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/26 14:29:12 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int	__close__(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	__exit__(NULL, vars, SUCCESS);
	return 1;	
}

void	quit_error(char *msg, char *line)
{
	if (line)
		free(line);
	ft_putstr("Error\n");
	if(msg)
		ft_putstr(msg);
	exit(EXIT_FAILURE);
}

void  _free_(void *vars)
{
	if (vars)
		free(vars);
	vars = NULL;	
}
void  free_vars(t_vars *vars)
{
	int i = 0;
	if (vars)
	{
		if (vars->img) 
		{
			mlx_destroy_image(vars->mlx, vars->img->img);
			_free_(vars->img);
		}
		if (vars->key)
			 _free_(vars->key);
		if (vars->mouv)
		 	_free_(vars->mouv);
		if (vars->mlx)
		{
			mlx_destroy_window(vars->mlx, vars->win);
		 	_free_(vars->mlx);
		}
		if (vars->map)
		{
			while (vars->map[i])
				 _free_(vars->map[i++]);
			 _free_(vars->map);
		}
		 _free_(vars);
	}
}
void	__exit__(char *msg, t_vars *vars, int ret)
{
	if (msg)
		ft_putstr(msg);
	if (vars)
		free_vars(vars);
	exit(ret);
}
