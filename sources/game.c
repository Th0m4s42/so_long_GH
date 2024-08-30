/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:33:27 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/30 14:03:10 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	start_game(t_map *map)
{
	t_game data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return ;
	data.win_ptr = mlx_new_window(data.mlx_ptr, ((map->column - 1) * 32), (map->line * 32), "so_long");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return ;
	}
	draw_map(&data, map);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, &data.coll);
	mlx_destroy_image(data.mlx_ptr, &data.player);
	mlx_destroy_image(data.mlx_ptr, &data.ground);
	mlx_destroy_image(data.mlx_ptr, &data.exit);
	mlx_destroy_image(data.mlx_ptr, &data.wall);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free_tab(map->content);
	free(map);
	free(data.mlx_ptr);
}

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_keypress(int keysym, t_game *data)
{
	if(keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// if(keysym == XK_w || keysym == XK_Up)
	// if(keysym == XK_a || keysym == XK_Left)
	// if(keysym == XK_s || keysym == XK_Down)
	// if(keysym == XK_d || keysym == XK_Right)
	printf("Keypress: %d\n", keysym);
	return (0);
}
