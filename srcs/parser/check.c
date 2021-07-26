/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:12:47 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/26 16:52:39 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_is_file(char **av)
{
	int i ;

	i = ft_strlen(av[1]);
	while (av[1][i] != '.' )
	{
		if (i == 0)
			quit_error("file error\n", NULL);
		i--;
	}
	i++;
	if (ft_strcmp((av[1] + i), "ber") != 0)
		quit_error("file error\n", NULL);
	return (1);
}

static int  map_is_one(char *str, int first_last_line, int len)
{
	int i;

	if (first_last_line == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] != '1')
				quit_error("map error\n", str);
			i++;
		}
	}
	else
	{
		if ((str[0] != '1') || (str[len - 1] != '1'))
			quit_error("map error\n", str);
	}
	return (1);
}

static int check_is_nbr(char *str)
{
	int i = 0;
	if(!str)
		return(0);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P' && str[i] != 'C' && str[i] != 'E')
			quit_error("nbr error\n", str);
		i++;
	}
	return (1);
}

static int check_play(char *str, int r)
{
	const char play[] = {'C', 'E', 'P'};
	static int nbr[3] = {0};
	int j;
	int i;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 3)
		{
			if (str[i] == play[j])
				nbr[j]++;
			j++;
		} 
		i++;
	}
	i = 0;
	if (!r)
	{
		while (i < 3)
		{
			if(nbr[i++] < 1 || nbr[2] > 1)
				quit_error("nbr error\n", str);
		} 
	}
	return (1);
}

t_check check_is_map(char *av)
{
	t_check check;
		
	ft_bzero(&check, sizeof(t_check));
	check.len = -1;
	check.read = 1;
	check.fd = open(av, O_RDONLY);
	if (check.fd < 0)
		quit_error("Error\nmap no exist\n", NULL);
	while (check.read > 0)
	{
		check.prev_len = check.len;
		check.read = get_next_line(check.fd, &check.line);
		check.len = ft_strlen(check.line);
		if (check.prev_len != -1 && check.prev_len != check.len)
		{
		   quit_error("Error\nmap error\n", check.line);
		}
		check_play(check.line, check.read);
		check_is_nbr(check.line);
		if (check.i++ == 0 || check.read == 0)
			map_is_one(check.line, 1, check.len);
		else
			map_is_one(check.line, 0, check.len);
		free(check.line);
	}
	close(check.fd);
	return (check);
}


