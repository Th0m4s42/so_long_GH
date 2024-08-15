/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:38:21 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/15 10:41:44 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int check_wall(t_map *map)
{
	int error_code;

	error_code = check_border(map);
	if (error_code != 0)
		return error_code;
	error_code = check_side(map);
	return (error_code);
}

int	check_border(t_map *map)
{
	int h;
	int w;

	w = 0;
	while (map->content[0][w] && map->content[0][w] != '\n')
	{
		if (map->content[0][w] != '1')
			return (413);
		w++;
	}
	h = 0;
	while(map->content[h])
		h++;
	w = 0;
	while (map->content[h - 1][w] && map->content[h - 1][w] != '\n')
	{
		if (map->content[h - 1][w] != '1')
			return (413);
		w++;
	}
	return (0);
}

int	check_side(t_map *map)
{
	int h;
	int w;

	h = 0;
	while (map->content[h])
	{
		if (map->content[h][0] != '1')
			return (413);
		h++;
	}
	h = 0;
	w = ft_strlen(map->content[0]) - 1;
	while (map->content[h])
	{
		if (map->content[h][w] != '1')
			return (413);
		h++;
	}
	return (0);
}
