/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:33:27 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/10 18:54:21 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	start_game(t_map *map)
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		return ;
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr, ((map->column - 1) * 32), (map->line * 32), "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		return ;
	}
	init_sprites(game);
	draw_map(game, map);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_loop(game->mlx_ptr);
	mlx_destroy_image(game->mlx_ptr, game->coll.adr);
	mlx_destroy_image(game->mlx_ptr, game->player.adr);
	mlx_destroy_image(game->mlx_ptr, game->ground.adr);
	mlx_destroy_image(game->mlx_ptr, game->exit.adr);
	mlx_destroy_image(game->mlx_ptr, game->wall.adr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
}

int	handle_keypress(int keysym, t_game *game, t_map *map)
{
	if(keysym == XK_Escape)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if(keysym == XK_w || keysym == XK_Up)
		movement(game, game->player.x, game->player.y - 1, map);
	if(keysym == XK_a || keysym == XK_Left)
		movement(game, game->player.x - 1, game->player.y, map);
	if(keysym == XK_s || keysym == XK_Down)
		movement(game, game->player.x, game->player.y + 1, map);
	if(keysym == XK_d || keysym == XK_Right)
		movement(game, game->player.x + 1, game->player.y, map);
	printf("Keypress: %d\n", keysym);
	return (0);
}

void	movement(t_game *game, int x, int y, t_map *map)
{
	int	previous_x;
	int	previous_y;
	int	move;

	previous_x = game->player.x;
	previous_y = game->player.y;
	move = 0;
	// if (map->content[y][x] == 'E' && map->C == 0)
	// victory
	if (map->content[y][x] == '0' || map->content[y][x] == 'C')
	{
		map->content[previous_y][previous_x] = '0';
		if (map->content[y][x] == 'C')
			map->C--;
		game->player.x = x;
		game->player.y = y;
		map->content[y][x] = 'P';
		move++;
		ft_printf("movement: %d", move);
		draw_map(game, map);
	}
}
