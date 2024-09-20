/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:23:59 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/20 17:54:31 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_map(t_map *map, char **argv)
{
	int		error_code;
	int		fd;
	int		lines;
	int		i;

	init_map(map);
	error_code = 0;
	i = 0;
	lines = count_lines(&argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (lines < 0)
		return (1);
	map->line = lines;
	map->content = malloc((lines + 1) * sizeof(char *));
	if (map->content == NULL)
		return (69);
	map->content[lines] = NULL;
	while (i < lines)
	{
		map->content[i] = get_next_line(fd);
		i++;
	}
	error_code = ft_compare_line(map, lines);
	return (error_code);
}

int	ft_compare_line(t_map *map, int lines)
{
	int	error_code;
	int	i;

	error_code = 0;
	i = 0;
	map->column = ft_strlen(map->content[0]);
	while (i < lines)
	{
		if (map->column != (int)ft_strlen(map->content[i]))
			error_code = 407;
		i++;
	}
	return (error_code);
}

int	check_game_item(t_map *map)
{
	int	error_code;

	error_code = 0;
	check_map_contain(map);
	if (map->P == 0)
		error_code = 408;
	else if (map->P > 1)
		error_code = 409;
	else if (map->E == 0)
		error_code = 410;
	else if (map->E > 1)
		error_code = 411;
	else if (map->C == 0)
		error_code = 412;
	else if (error_code == 0)
		error_code = check_map_unexpexted_contain(map);
	return (error_code);
}

void	check_map_contain(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (map->content[h])
	{
		w = 0;
		while (map->content[h][w])
		{
			if (map->content[h][w] == 'P')
				map->P++;
			else if (map->content[h][w] == 'E')
				map->E++;
			else if (map->content[h][w] == 'C')
			{
				map->C++;
			}
			w++;
		}
		h++;
	}
}

int	check_map_unexpexted_contain(t_map *map)
{
	int	h;
	int	w;
	int	error_code;

	h = 0;
	error_code = 0;
	while (map->content[h])
	{
		w = 0;
		while (map->content[h][w])
		{
			if (map->content[h][w] != 'P' && map->content[h][w] != 'E' &&
				map->content[h][w] != 'C' && map->content[h][w] != '1' &&
				map->content[h][w] != '0' && map->content[h][w] != '\n' &&
				map->content[h][w])
			{
				error_code = 414;
			}
			w++;
		}
		h++;
	}
	return (error_code);
}
