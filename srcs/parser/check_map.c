/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:00:04 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/21 18:48:33 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_value(t_vars *vars, t_check check)
{
    vars->map_x_len = check.len;
    vars->map_y_len = check.i;
}

// void    draw_map(t_vars *vars)
// {
//     int i;

//     i = 0;
//     vars->map[i] 
// }

void parsing(char *av, t_vars *vars)
{
    t_check check;
 
    int i = 0;
    
    check = check_is_map(av);
    vars->map = ft_calloc(sizeof(char *), (check.i + 1));
    if (!vars->map)
        __exit__("Error malloc\n", vars, FAILURE);
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