/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:40:04 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/12 18:19:23 by thbasse          ###   ########.fr       */
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

int	check_error(int argc, char **argv, t_map *map)
{
	int		error_code;

	error_code = 0;
	error_code = get_error_code(argc, argv, map);
	print_error(error_code);
	return (error_code);
}

int	get_error_code(int argc, char **argv, t_map *map)
{
	int	error_code;
	int fd;

	error_code = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		error_code = 300;
	else if (fd == -1)
		error_code = 404;
	else
	{
		close(fd);
		if (ft_checkname((const char *)argv[1]) == 22)
			error_code = 406;
		else if (error_code == 0)
			error_code = check_map(map, argv);
		else
			error_code = check_game_item(map);
	}
	return (error_code);
}

int	print_error(int error_code)
{
	if (error_code == 300)
		ft_printf("ERROR_INVALID_PARAMETER\n");
	else if (error_code == 404)
		ft_printf("ERROR_UNWINNABLE\n");
	else if (error_code == 415)
		ft_printf("ERROR_FILE_NOT_FOUND\n");
	else if (error_code == 406)
		ft_printf("ERROR_FORMAT_FILE\n");
	else if (error_code == 407)
		ft_printf("ERROR_WRONG_SHAPE_OF_MAP\n");
	else if (error_code == 408)
		ft_printf("ERROR_NO_PLAYER\n");
	else if (error_code == 409)
		ft_printf("ERROR_TOO_MUCH_PLAYER\n");
	else if (error_code == 410)
		ft_printf("ERROR_NO_EXIT\n");
	else if (error_code == 411)
		ft_printf("ERROR_TOO_MUCH EXIT\n");
	else if (error_code == 412)
		ft_printf("ERROR_NO_COLLECTIBLE\n");
	else if (error_code == 413)
		ft_printf("ERROR_WALL_MISSING\n");
	else if (error_code == 414)
		ft_printf("ERROR_UNEXPECTED_ELEMENT\n");
	return (0);
}
