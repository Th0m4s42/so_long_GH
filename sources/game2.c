/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:00:43 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/21 10:03:19 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_all(t_game *game)
{
	destroy(game);
	free_tab(game->map.content);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	destroy(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->coll.adr);
	mlx_destroy_image(game->mlx_ptr, game->player.adr);
	mlx_destroy_image(game->mlx_ptr, game->ground.adr);
	mlx_destroy_image(game->mlx_ptr, game->exit.adr);
	mlx_destroy_image(game->mlx_ptr, game->wall.adr);
}

void	victory(t_game *game)
{
	ft_printf("CONGRATULATIONS!\n");
	free_all(game);
}
