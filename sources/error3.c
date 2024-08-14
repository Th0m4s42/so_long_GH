/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:38:21 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/14 20:06:10 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int check_wall(t_map *map)
{
	int error_code;

	error_code = 0;
	error_code = check_boder(map);
	if (error_code == 0)
		error_code =check_side(map);
	return (error_code);
}

int	check_boder(t_map *map)
{
	int h;
	int w;
	int	error_code;

	error_code = 0;
	w = 0;
	while (map->content[0][w])
	{
		if (map->content[0][w] != '1')
			error_code = 413;
		w++;
	}
	w = 0;
	h = 0;
	while(map->content[h])
		h++;
	while (map->content[h - 1][w] != '\n')
	{
		if (map->content[h - 1][w] != '1')
			error_code = 413;
		w++;
	}
	return(error_code);
}

int	check_side(t_map *map)
{
	int h;
	int w;
	int	error_code;

	error_code = 0;
	h = 0;
	while (map->content[h][0])
	{
		if (map->content[h][0] != '1')
			error_code = 413;
		h++;
	}
	h = 0;
	w = ft_strlen(map->content[0]);
	while (map->content[h][w - 1])
	{
		if (map->content[h - 1][w - 1] != '1')
			error_code = 413;
		h++;
	}
	return(error_code);
}
