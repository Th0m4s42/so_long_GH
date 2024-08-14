/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:27:05 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/14 15:32:01 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char **argv)
{
	int		error_code;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (1);
	error_code = check_error(argc, argv, map);
	if (error_code > 406 || error_code == 0)
		free_tab(map->content);
	free(map);
}
