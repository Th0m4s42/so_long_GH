/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:29:26 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/21 10:04:05 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_map(t_map *map)
{
	map->content = NULL;
	map->line = 0;
	map->column = 0;
	map->p = 0;
	map->c = 0;
	map->e = 0;
}

int	count_lines(char **map)
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
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		nb++;
	}
	close(fd);
	return (nb);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_player	*create_player(int x, int y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->x = x;
	player->y = y;
	return (player);
}

void	free_visited(bool **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
