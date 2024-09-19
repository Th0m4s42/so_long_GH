/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:33:27 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/19 21:21:51 by thbasse          ###   ########.fr       */
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
	{
		free(game);
		return ;
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, ((map->column - 1) * 32), (map->line * 32), "so_long");
	if (game->win_ptr == NULL)
	{
		free(game);
		return ;
	}
	init_game(game, map);
	init_sprites(game);
	draw_map(game);
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
	if(keysym == XK_Escape || keysym == 113)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if(keysym == 119 || keysym == 65362)
		movement(game, game->player.x, game->player.y - 1, map);
	if(keysym == 97 || keysym == 65361)
		movement(game, game->player.x - 1, game->player.y, map);
	if(keysym == 115 || keysym == 65364)
		movement(game, game->player.x, game->player.y + 1, map);
	if(keysym == 100 || keysym == 65363)
		movement(game, game->player.x + 1, game->player.y, map);
	printf("Keypress: %d\n", keysym);
	return (0);
}

void	movement(t_game *game, int x, int y, t_map *map)
{
	int	previous_x;
	int	previous_y;
	int	move;

	previous_x = game->player_pos.x;
	previous_y = game->player_pos.y;
	move = 0;
	// if (map->content[y][x] == 'E' && map->C == 0)
	// victory
	if (map->content[y][x] == '0' || map->content[y][x] == 'C')
	{
		map->content[previous_y][previous_x] = '0';
		if (map->content[y][x] == 'C')
			map->C--;
		game->player_pos.x = x;
		game->player_pos.y = y;
		map->content[y][x] = 'P';
		move++;
		// ft_printf("movement: %d", move);
		draw_map(game);
	}
}
 
void	init_game(t_game *game, t_map *map)
{
	game->player.adr = NULL;
	game->coll.adr = NULL;
	game->exit.adr = NULL;
	game->wall.adr = NULL;
	game->ground.adr = NULL;
	game->map.content = map->content;
	game->map.line = map->line;
	game->map.column = map->column;
	game->map.P = map->P;
	game->map.C = map->C;
	game->map.E = map->E;
	get_player_pos(game, map);
}

void	get_player_pos(t_game *game, t_map *map)
{
	int			h;
	int			w;

	h = 0;
	while (map->content[h])
	{
		w = 0; 
		while (map->content[h][w])
		{
			if (map->content[h][w] == 'P')
			{
				game->player_pos.y = h;
				game->player_pos.x = w;
				return ;
			}
			w++;
		}
		h++;
	}
}
