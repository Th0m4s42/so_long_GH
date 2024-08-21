/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphism.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:00:07 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/21 19:55:25 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_image	init_sprites(t_game *game)
{
	t_image	sprite;
	
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_new_sprite(mlx, "resouces/Textures/Grave.xpm", game);
	game->ground = ft_new_sprite(mlx, "resouces/Textures/ground.xpm", game);
	game->coll = ft_new_sprite(mlx, "resouces/Textures/Soul.xpm", game);
	game->player = ft_new_sprite(mlx, "resouces/Textures/Reaper.xpm", game);
	game->exit = ft_new_sprite(mlx, "resouces/Textures/Exit.xpm", game);
	return (sprite);
}	

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image sprite;

	sprite.adr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.adr == NULL)
		ft_putendl_fd("ERROR_SPRITE_NOT_FOUND", 2);
	return (sprite);
}

void	draw_map(t_image *game, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->line);
	{
		x = 0;
		while (x < map->column)
		{
			draw_sprites(game, map, x, y);
			x++;
		}
		y++;
	}
}

void	draw_sprites(t_game *game, t_map *map, int x, int y)
{

}
