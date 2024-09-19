/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphism.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:00:07 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/19 20:02:45 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_new_sprite(mlx, "resources/Textures/Grave.xpm", game);
	game->ground = ft_new_sprite(mlx, "resources/Textures/ground.xpm", game);
	game->coll = ft_new_sprite(mlx, "resources/Textures/Soul.xpm", game);
	game->player = ft_new_sprite(mlx, "resources/Textures/Reaper.xpm", game);
	game->exit = ft_new_sprite(mlx, "resources/Textures/Exit.xpm", game);
}	

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image sprite;

	sprite.adr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.adr == NULL)
	{
		ft_putendl_fd("ERROR_SPRITE_NOT_FOUND", 2);
		exit (EXIT_FAILURE);
	}
	return (sprite);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < game->map.line)
	{
		x = 0;
		while (x < game->map.column)
		{
			draw_sprites(game, x, y);
			x++;
		}
		y++;
	}
}

void	draw_sprites(t_game *game, int x, int y)
{
	if (game->map.content[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.adr, x * game->wall.x, y * game->wall.y);
	else if (game->map.content[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->ground.adr, x * game->ground.x, y * game->ground.y);
	else if (game->map.content[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.adr, x * game->player.x, y * game->player.y);
	else if (game->map.content[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->coll.adr, x * game->coll.x, y * game->coll.y);
	else if (game->map.content[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit.adr, x * game->exit.x, y * game->exit.y);
}
