/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:27:46 by thbasse           #+#    #+#             */
/*   Updated: 2024/07/05 14:09:05 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <limits.h>
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

////////////STRUCTURES/////////////////////////////////////////////////////////

typedef struct  s_map
{
    char    *name;
    char    *addr;
}               t_map;

////////////FONCTIONS//////////////////////////////////////////////////////////

int	main(int argc, char **argv);

#endif
