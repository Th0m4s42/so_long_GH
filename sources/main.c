/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:27:05 by thbasse           #+#    #+#             */
/*   Updated: 2024/07/05 15:42:14 by thbasse          ###   ########.fr       */
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
			return(22);
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_printf("ERROR: wrong argument(s)\n");
	else if (open(argv[1], O_RDONLY) == -1)
		ft_printf("ERROR: file not found\n");
	else if (open(argv[1], O_RDONLY) != -1)
	{
		if (ft_checkname((const char *)argv[1]) == 22)
			ft_printf("ERROR: wrong format\n");
		else
			ft_printf("TOUT EST BON POUR L'INSTANT\n");
	}
}
