/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:40:04 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/09 17:37:02 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	ft_checkname(const char *str)
{
	while (str)
	{
		if (*str == '.')
		{
			if (ft_strncmp((const char *)str, ".ber", 5) == 0)
				return (0);
			else
				return (22);
		}
		else if (*str == '\0')
			return (22);
		str++;
	}
	return (0);
}

void	check_error(int argc, char **argv, t_map *map)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		ft_printf("ERROR: wrong argument(s)\n");
	else if (fd == -1)
		ft_printf("ERROR: file not found\n");
	else
	{
		close(fd);
		if (ft_checkname((const char *)argv[1]) == 22)
			ft_printf("ERROR: wrong format\n");
		else
		{
			init_map(map, argv);
			ft_printf("TOUT EST BON POUR L'INSTANT\n");
		}
	}
}
