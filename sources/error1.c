/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:40:04 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/21 09:07:00 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_error(int argc, char **argv, t_map *map)
{
	int		error_code;

	error_code = 0;
	error_code = get_error_code(argc, argv, map);
	print_error(error_code);
	if (error_code < 407 && error_code != 0)
	{
		free(map);
		exit (0);
	}
	if (error_code > 0)
	{
		free_tab(map->content);
		free(map);
		exit (EXIT_FAILURE);
	}
}

int	get_error_code(int argc, char **argv, t_map *map)
{
	int	error_code;
	int	fd;

	error_code = 0;
	if (argc != 2)
		return (300);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (404);
	close(fd);
	if (ft_checkname((const char *)argv[1]) == 22)
		error_code = 406;
	if (error_code == 0)
		error_code = check_map(map, argv);
	if (error_code == 0)
		error_code = check_game_item(map);
	if (error_code == 0)
		error_code = check_wall(map);
	if (error_code == 0)
		error_code = check_rechability(map);
	return (error_code);
}

int	ft_checkname(const char *str)
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

void	print_error(int error_code)
{
	if (error_code == 300)
		ft_putendl_fd("ERROR_INVALID_PARAMETER\n", 2);
	else if (error_code == 415)
		ft_putendl_fd("ERROR_UNWINNABLE\n", 2);
	else if (error_code == 405)
		ft_putendl_fd("ERROR_FILE_NOT_FOUND\n", 2);
	else if (error_code == 406)
		ft_putendl_fd("ERROR_FORMAT_FILE\n", 2);
	else if (error_code == 407)
		ft_putendl_fd("ERROR_WRONG_SHAPE_OF_MAP\n", 2);
	else if (error_code == 408)
		ft_putendl_fd("ERROR_NO_PLAYER\n", 2);
	else if (error_code == 409)
		ft_putendl_fd("ERROR_TOO_MUCH_PLAYER\n", 2);
	else if (error_code == 410)
		ft_putendl_fd("ERROR_NO_EXIT\n", 2);
	else if (error_code == 411)
		ft_putendl_fd("ERROR_TOO_MUCH_EXIT\n", 2);
	else if (error_code == 412)
		ft_putendl_fd("ERROR_NO_COLLECTIBLE\n", 2);
	else if (error_code == 413)
		ft_putendl_fd("ERROR_WALL_MISSING\n", 2);
	else if (error_code == 414)
		ft_putendl_fd("ERROR_UNEXPECTED_ELEMENT\n", 2);
}
