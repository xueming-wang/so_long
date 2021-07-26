/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:14:57 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/26 17:53:23 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void counter_bonus(t_vars *vars)
{
    const char *str = ft_itoa(vars->counter);
    if (!str)
        __exit__(NULL, vars, FAILURE);
    mlx_string_put(vars->mlx, vars->win, 100, 100, 0xFF0000, (char *)str);
    free((char *)str);
}