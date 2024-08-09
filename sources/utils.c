/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:29:26 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/09 16:58:23 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int count_lines(char **map)
{
	int		fd;
	int		nb;
	char	*line;

	nb = 0;
	fd = open(map[1], O_RDONLY);
	while(get_next_line(fd) != NULL)
	{
		line = get_next_line(fd);
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

void	ft_compare_line(t_map *map, int lines)
{
	int	i;

	i = 0;
	ft_strlen(map->content[0]);
	while (i < lines)
	{
		if (ft_strlen(map->content[0]) != ft_strlen(map->content[i]))
			ft_printf("ERROR: Map is not a square\n");
		i++;
	}
}

int	init_map(t_map *map, char **argv)
{
	int		fd;
	int		lines;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	lines = count_lines(&argv[1]);
	map->line = lines;
	map->content = malloc(lines * sizeof (char **));
	while (get_next_line(fd) != NULL)
	{
		map->content[i] = get_next_line(fd);
		i++;
	}
	ft_compare_line(map, lines);
	return (0);
}
