/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:33:27 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/20 17:59:44 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	start_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		return ;
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game);
		return ;
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, ((map->column - 1) * 32),
			(map->line * 32), "so_long");
	if (game->win_ptr == NULL)
	{
		free(game);
		return ;
	}
	init_game(game, map);
	init_sprites(game);
	draw_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, 17, 1L << 19, &free_all, game);
	mlx_loop(game->mlx_ptr);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape || keysym == 113)
	{
		free_all(game);
		exit (0);
	}
	if (keysym == 119 || keysym == 65362)
		movement(game, game->player_pos.x, game->player_pos.y - 1);
	if (keysym == 97 || keysym == 65361)
		movement(game, game->player_pos.x - 1, game->player_pos.y);
	if (keysym == 115 || keysym == 65364)
		movement(game, game->player_pos.x, game->player_pos.y + 1);
	if (keysym == 100 || keysym == 65363)
		movement(game, game->player_pos.x + 1, game->player_pos.y);
	return (0);
}

void	movement(t_game *game, int x, int y)
{
	int			previous_x;
	int			previous_y;
	static long	move = 0;

	previous_x = game->player_pos.x;
	previous_y = game->player_pos.y;
	if (game->map.content[y][x] == 'E' && game->map.C == 0)
	{
		move++;
		ft_printf("YOU WIN WITH %d MOVEMENT", move);
		victory(game);
	}
	if (game->map.content[y][x] == '0' || game->map.content[y][x] == 'C')
	{
		game->map.content[previous_y][previous_x] = '0';
		if (game->map.content[y][x] == 'C')
			game->map.C--;
		game->player_pos.x = x;
		game->player_pos.y = y;
		game->map.content[y][x] = 'P';
		move++;
		ft_printf("movement: %d\n", move);
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
	get_player_pos(game);
}

void	get_player_pos(t_game *game)
{
	int			h;
	int			w;

	h = 0;
	while (h < game->map.line)
	{
		w = 0;
		while (w < game->map.column)
		{
			if (game->map.content[h][w] == 'P')
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

int	free_all(t_game *game)
{
	destroy(game);
	free_tab(game->map.content);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	return(0);
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
	free_all(game);
	ft_printf("CONGRATULATIONS!\n");
}
