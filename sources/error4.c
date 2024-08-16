/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:12:54 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/16 18:59:35 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int		check_rechability(t_map *map)
{
	bool 		**visited;
	int			h;
	int			w;
	t_player	*pos;

	h = 0;
	pos = check_player_pos(map);
	if (pos == NULL)
		return (-1);
	visited = init_visited(map);
	if (visited == NULL)
		return (-1);
	depth_first_search(map->content, pos->y, pos->x, map->column, map->line,
	visited);
	while(h < map->column)
	{
		w = 0;
		while (w < map->line)
		{
			if ((map->content[h][w] == 'C' || map->content[h][w] == 'E') &&
				!visited[h][w])
			{
				free_visited(visited, map->column);
				free(pos);
				return (415);
			}
			w++;
		}
		h++;
	}
	free_visited(visited, map->column);
	free(pos);
	return (0);
}

t_player	*check_player_pos(t_map *map)
{
	int			h;
	int			w;
	t_player	*pos;

	h = 0;
	pos = create_player(0, 0);
	if (pos == NULL)
		return (NULL);
	while (map->content[h])
	{
		w = 0; 
		while (map->content[h][w])
		{
			if (map->content[h][w] == 'P')
			{
				pos->y = h;
				pos->x = w;
				return (pos);
			}
			w++;
		}
		h++;
	}
	free (pos);
	return (NULL);
}

bool	**init_visited(t_map *map)
{
	int		h;
	int		w;
	bool	**visited;

	h = 0;
	visited = malloc(sizeof (bool *) * map->column);
	if (visited == NULL)
		return (NULL);
	while (h < map->column)
	{
		visited[h] = malloc(sizeof(bool) * map->line);
		if (visited[h] == NULL)
		{
			free_visited(visited, h);
			return (NULL);
		}
		w = 0;
		while (w < map->line)
		{
			visited[h][w] = false;
			w++;
		}
		h++;
	}
	return (visited);
}

void	depth_first_search(char **map, int h, int w, int max_h, int max_w,
bool **visited)
{
	if (h < 0 || h >= max_h || w < 0 || w >= max_w)
		return ;
	if (map[h][w] == '1' || visited[h][w] == true)
		return ;
	visited[h][w] = true;
	depth_first_search(map, h - 1, w, max_h, max_w, visited);
	depth_first_search(map, h + 1, w, max_h, max_w, visited);
	depth_first_search(map, h, w - 1, max_h, max_w, visited);
	depth_first_search(map, h, w + 1, max_h, max_w, visited);
}
