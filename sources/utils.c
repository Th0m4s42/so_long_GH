/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:29:26 by thbasse           #+#    #+#             */
/*   Updated: 2024/07/29 16:18:41 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	init_map(t_map *map, char **argv)
{
	int		fd;
	int		i;
	int		j;

	char	*line;

	fd = open(argv[1], O_RDONLY);
	j = 0;
	i = 0;
	map->content = (char **)malloc(BUFFER_SIZE * sizeof(char *));
	if (map->content == NULL)
	{
		perror("ERROR: malloc for lines failed");
		close(fd);
	}
	while (j < BUFFER_SIZE)
		map->content[j++] = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		map->content[i] = (char *)malloc((ft_strlen(line) + 1) * sizeof(char *));
		if (map->content[i] == NULL)
		{
			perror("ERROR: malloc for one line failed");
			free(line);
		}
		ft_strlcpy(map->content[i], line, ft_strlen(line) + 1);
		free (line);
		i++;
	}
	return (14);
}
