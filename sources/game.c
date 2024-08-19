/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:33:27 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/19 16:35:59 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	start_game(t_map *map)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return ;
	win_ptr = mlx_new_window(mlx_ptr, (map->column * 32), (map->line * 32), "so_looong");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return ;
	}
	// mlx_loop_hook(mlx_ptr, &handle_no_event, win_ptr);
	mlx_loop(mlx_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}

// static int	handle_keypress(int keysym, void *mlx_ptr, void *win_ptr)
// {
// 	if(keysym == XK_Escape)
// 		mlx_destroy_window(mlx_ptr, win_ptr);
// 	printf("Keypress: %d\n", keysym);
// 	return (0);
// }

// static int	handle_no_event()
// {
// 	return (0);
// }
