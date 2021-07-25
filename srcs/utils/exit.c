/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:08:05 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/23 13:02:12 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit_error(char *msg, char *line)
{
	if (line)
		free(line);
	ft_putstr("Error\n");
	if(msg)
		ft_putstr(msg);
	exit(EXIT_FAILURE);
}

void	__exit__(char *msg, t_vars *vars, int ret)
{
	if (msg)
	{
		ft_putstr(msg);
	}
	if (vars)
	{
		if (vars->img)
		{
			free(vars->img);
			vars->img = NULL;
		}
		if (vars->key)
		{
			free(vars->key);
			vars->key = NULL;
		}
		if (vars->mouv)
		{
			free(vars->mouv);
			vars->mouv = NULL;
		}
		free(vars);
		vars = NULL;
	}
	exit(ret);
}
