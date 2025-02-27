/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:15:34 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/26 17:15:37 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_moves_display(t_game *game)
{
	free(game->moves_str);
	game->moves_str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 10, 0xFFFFFF, game->moves_str);
}
