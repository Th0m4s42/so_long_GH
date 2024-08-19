/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:27:46 by thbasse           #+#    #+#             */
/*   Updated: 2024/08/19 11:56:12 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1024

# include <stdbool.h>
# include <limits.h>
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

////////////STRUCTURES/////////////////////////////////////////////////////////

typedef struct 	s_map
{
	char	**content;
	int		line;
	int		column;
	int		P;
	int		C;
	int		E;
}				t_map;

typedef struct	s_player
{
	int	x;
	int	y;
}				t_player;

////////////FONCTIONS//////////////////////////////////////////////////////////

int		main(int argc, char **argv);

////////////ERROR//////////////////////////////////////////////////////////////

int			check_error(int argc, char **argv, t_map *map);
int			get_error_code(int argc, char **argv, t_map *map);
int			ft_checkname(const char *str);
int			check_map(t_map *map, char **argv);
int			ft_compare_line(t_map *map, int lines);
int			check_game_item(t_map *map);
void		check_map_contain(t_map *map);
int			check_map_unexpexted_contain(t_map *map);
int			print_error(int error_code);
int			check_wall(t_map *map);
int			check_border(t_map *map);
int			check_side(t_map *map);
int			check_rechability(t_map *map);
t_player	*check_player_pos(t_map *map);
bool		**init_visited(t_map *map);
void		depth_first_search(char **map, int h, int w, int max_h, int max_w,
			bool **visited);
int			check_visited(t_map *map, bool **visited);

////////////UTILS//////////////////////////////////////////////////////////////

void		init_map(t_map *map);
int			count_lines(char **map);
void		free_tab(char **tab);
t_player	*create_player(int x, int y);
void		free_visited(bool **visited, int height);

#endif
