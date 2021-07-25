/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:00:04 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/23 13:03:16 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_value(t_vars *vars, t_check check)  //得到c的数量collect和地图的长格数和竖着的格数vars->map_x_len，map_y_len
{
    int i = 0;
    int j;
    vars->collect = 0;
    while (vars->map[i])
    {
        j = 0;
        while (vars->map[i][j])
        {
            if (vars->map[i][j] == 'C')
                vars->collect++;
            if (vars->map[i][j] == 'P')
            {
                vars->mouv->x = j;
                vars->mouv->y = i;
                vars->map[i][j] = '0';
            }
            j++;
        } 
        i++;
    }
    vars->map_x_len = check.len;
    vars->map_y_len = check.i;
}

void parsing(char *av, t_vars *vars)  //把得到的地图和数值保存起来 
{
    t_check check;
 
    int i = 0;
    
    check = check_is_map(av);
    vars->map = ft_calloc(sizeof(char *), (check.i + 1));
    if (!vars->map)
        __close__(vars);
    check.fd = open(av, O_RDONLY);
    check.read = 1;
    while (check.read)
    {
        check.read = get_next_line(check.fd, &check.line);
        vars->map[i++] = ft_strdup(check.line);
        free(check.line);
    }
    close(check.fd);
    get_value(vars, check);
}