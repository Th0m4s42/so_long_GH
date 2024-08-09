/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:29:26 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/09 16:38:26 by thbasse          ###   ########.fr       */
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

int	init_map(t_map *map, char **argv)
{
	int		fd;
	int		lines;

	fd = open(argv[1], O_RDONLY);
	lines = count_lines(&argv[1]);
	map->line = lines;
	/*
	stocker ligne
	comparer longueur
	verifier contenu
	verifier possibiliter de finir le jeu
	*/
	map->content = malloc(lines * sizeof (char **));
	
	return (0);
}
