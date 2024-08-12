/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:29:26 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/12 18:43:59 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int count_lines(char **map)
{
	int		fd;
	int		nb;
	char	*line;

	nb = 0;
	fd = open(*map, O_RDONLY);
	if (fd < 0)
	{
		perror(*map);
		return (-1);
	}
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		nb++;
	}
	close(fd);
	return(nb);
}
	/*
	stocker ligne
	comparer longueur
	verifier contenu
	verifier possibiliter de finir le jeu
	*/
void check_map_contain(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while(map->content[h])
	{
		while (map->content[h][w])
		{
			if (map->content[h][w] == 'P')
				map->P += 1;
			else if (map->content[h][w] == 'E')
				map->E += 1;
			else if (map->content[h][w] == 'C')
				map->C += 1;
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
	w = 0;
	error_code = 0;
	while(map->content[h])
	{
		while (map->content[h][w])
		{
			if (map->content[h][w] != 'P' ||
					map->content[h][w] != 'E' ||
					map->content[h][w] != 'C' ||
					map->content[h][w] != '1' ||
					map->content[h][w] != '0')
				error_code = 414;
			w++;
		}
		h++;
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

int	ft_compare_line(t_map *map, int lines)
{
	int error_code;
	int	i;

	error_code = 0;
	i = 0;
	ft_strlen(map->content[0]);
	while (i < lines)
	{
		if (ft_strlen(map->content[0]) != ft_strlen(map->content[i]))
			error_code = 407;
		i++;
	}
	return(error_code);
}

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

void init_map(t_map *map)
{
	map->content = NULL;
	map->line = 0;
	map->column = 0;
	map->P = 0;
	map->C = 0;
	map->E = 0;
}

