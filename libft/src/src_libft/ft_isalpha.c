/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:52:18 by thbasse           #+#    #+#             */
/*   Updated: 2023/11/06 17:39:16 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha( int character )
{
	if ((character > 64 && character < 91)
		|| (character > 96 && character < 123))
		return (1);
	else
		return (0);
}
