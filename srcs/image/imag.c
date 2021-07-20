/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:17:39 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/20 14:57:38 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)    //找到点 放上颜色
{
	char	*dst;

	dst = vars->img->addr + (y * vars->img->line_len + x * (vars->img->bits_per_pixel / 8));   //addr图片地址
	*(unsigned int*)dst = color;
}