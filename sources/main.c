/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:27:05 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/09 17:53:03 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char **argv)
{
	int		i;
	t_map	*map;
	
	i = 0;
	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (1);
	check_error(argc, argv, map);
	while(map->content[i] != NULL)
	{
		free(map->content[i]);
		i++;
	}
	free(map->content);
	free(map);
}
