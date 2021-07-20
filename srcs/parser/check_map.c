/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:00:04 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/20 17:26:07 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_value(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    while (vars->map[i])
    {
        j = 0;
        while (vars->map[i][j])
        {
            if (vars->map[i][j] == 'P')
            {
                vars->mouv->x = j;
                vars->mouv->y = i;
                vars->map[i][j] == '0';
            }
            if (vars->map[i][j] == 'C')
            {
                
            }
            j++;
        }
        i++;
    }
}

void parsing(char *av, t_vars *vars)
{
    t_check check;
    t_check map;
    
    int i = 0;
    check = check_is_map(av);
    vars->map = malloc(sizeof(char *) * check.i);
    if (!vars->map)
        __exit__("Error malloc\n", vars, FAILURE);
    ft_bzero(&map, sizeof(t_check));
    map.fd = open(av, O_RDONLY);
    map.read = 1;
    while (map.read)
    {
        map.read = get_next_line(map.fd, &map.line);
        vars->map[i++] = ft_strdup(map.line);
        free(map.line);
    }
    close(map.fd);
    
    
}